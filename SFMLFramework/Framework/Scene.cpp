#include "stdafx.h"


Scene::Scene(SceneIds id)
	:id(id)
{
}

void Scene::Init()
{
	drawObjects.push_back(std::list<GameObject*>());

	OnPreDraw();
	for (auto obj : gameObjects)
	{
		obj->Init();
	}
}

void Scene::Release()
{
	for (auto obj : gameObjects)
	{
		obj->Release();
		delete obj;
	}
	gameObjects.clear();
}

void Scene::Enter()
{
	for (auto obj : addGameObjs)
	{
		obj->Reset();
	}
	for (auto obj : gameObjects)
	{
		obj->Reset();
	}
}

void Scene::Exit()
{
	ApplyAddGo();
	ApplyRemoveGo();
}

void Scene::Update(float dt)
{
	for (auto obj : gameObjects)
	{
		if (!obj->IsActive())
		{
			continue;
		}
		obj->Update(dt);
	}
}

void Scene::LateUpdate(float dt)
{
}

void Scene::OnPreDraw()
{
	ApplyAddGo();
	ApplyRemoveGo();
}

void Scene::Draw(sf::RenderWindow& window)
{
	//std::priority_queue<GameObject*, std::vector<GameObject*>, DrawOrderComparer> drawqueue;

	for (auto& lstDrawObject : drawObjects)
	{
		for (auto obj : lstDrawObject)
		{
			if (!obj->IsActive())
			{
				continue;
			}
			obj->Draw(window);
			//drawqueue.push(obj);
		}
	}

	//while (!drawqueue.empty())
	//{
	//	GameObject* obj = drawqueue.top();
	//	obj->draw(window);
	//	drawqueue.pop();
	//}
}

void Scene::OnPostDraw()
{
	ApplyAddGo();
	ApplyRemoveGo();
	SortDrawObject();
}

void Scene::RemoveGo(GameObject* obj)
{
	gameObjectsChanged = true;
	removeGameObjs.push_back(obj);
}

GameObject* Scene::FindGo(const std::string& name)
{
	for (auto obj : gameObjects)
	{
		if (obj->GetName() == name)
		{
			return obj;
		}
	}
	return nullptr;
}

int Scene::FindGoAll(const std::string& name, std::list<GameObject*>& list)
{
	int cnt = 0;

	if (list.size() > 0)
	{
		for (auto obj : list)
		{
			obj->Release();
		}
		list.clear();
	}

	for (auto obj : gameObjects)
	{
		if (obj->GetName() == name)
		{
			++cnt;
			list.push_back(obj);
		}
	}


	return cnt;
}

void Scene::ApplyAddGo()
{
	for (auto go : addGameObjs)
	{
		if (std::find(gameObjects.begin(), gameObjects.end(), go) == gameObjects.end())
		{
			gameObjects.push_back(go);
		}
		if (drawView.size() == 0)
		{
			drawObjects.front().push_back(go);
		}
		else
		{
			//view가 하나 이상 설정되어 있을 시 뷰에 대해 만들기
		}
	}
	addGameObjs.clear();
}

void Scene::ApplyRemoveGo()
{
	for (auto go : removeGameObjs)
	{
		gameObjects.remove(go);
		if (drawView.size() == 0)
		{
			drawObjects.front().remove(go);
		}
		else
		{
			//view가 하나 이상 설정되어 있을 시 지우기 만들기
		}
	}

	removeGameObjs.clear();
}

void Scene::SortDrawObject()
{
	if (gameObjectsChanged)
	{
		return;
	}
	gameObjectsChanged = false;
	for (auto vecdrawObject : drawObjects)
	{
		std::stable_sort(vecdrawObject.begin(), vecdrawObject.end(), DrawOrderComparer());
	}
}
