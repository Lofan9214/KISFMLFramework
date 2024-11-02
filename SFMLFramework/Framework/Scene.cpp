#include "stdafx.h"


Scene::Scene(SceneIds id)
	:id(id)
{
}

void Scene::init()
{
	onPreDraw();
	for (auto obj : gameObjects)
	{
		obj->init();
	}
}

void Scene::release()
{
	for (auto obj : gameObjects)
	{
		obj->release();
		delete obj;
	}
	gameObjects.clear();
}

void Scene::enter()
{
	for (auto obj : addGameObjs)
	{
		obj->reset();
	}
	for (auto obj : gameObjects)
	{
		obj->reset();
	}
}

void Scene::exit()
{
	applyAddGo();
	applyRemoveGo();
}

void Scene::update(float dt)
{
	for (auto obj : gameObjects)
	{
		if (!obj->isActive())
		{
			continue;
		}
		obj->update(dt);
	}
}

void Scene::lateUpdate(float dt)
{
}

void Scene::onPreDraw()
{
	applyAddGo();
	applyRemoveGo();
}

void Scene::draw(sf::RenderWindow& window)
{
	std::priority_queue<GameObject*, std::vector<GameObject*>, DrawOrderComparer> drawqueue;

	for (auto obj : gameObjects)
	{
		if (!obj->isActive())
		{
			continue;
		}
		drawqueue.push(obj);
	}

	while (!drawqueue.empty())
	{
		GameObject* obj = drawqueue.top();
		obj->draw(window);
		drawqueue.pop();
	}
}

void Scene::onPostDraw()
{
	applyAddGo();
	applyRemoveGo();
}

void Scene::removeGo(GameObject* obj)
{
	removeGameObjs.push_back(obj);
}

GameObject* Scene::findGo(const std::string& name)
{
	for (auto obj : gameObjects)
	{
		if (obj->getName() == name)
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
			obj->release();
		}
		list.clear();
	}

	for (auto obj : gameObjects)
	{
		if (obj->getName() == name)
		{
			++cnt;
			list.push_back(obj);
		}
	}


	return cnt;
}

void Scene::applyAddGo()
{
	for (auto go : addGameObjs)
	{
		if (std::find(gameObjects.begin(), gameObjects.end(), go) == gameObjects.end())
		{
			gameObjects.push_back(go);
		}
	}
}

void Scene::applyRemoveGo()
{
	addGameObjs.clear();
	for (auto go : removeGameObjs)
	{
		gameObjects.remove(go);
	}
	removeGameObjs.clear();
}
