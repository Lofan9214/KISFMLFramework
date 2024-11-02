#include "stdafx.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneGame.h"

void SceneMgr::Init()
{
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());
	scenes.push_back(new SceneGame());

	for (auto scene : scenes)
	{
		scene->Init();
	}
	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;

}

void SceneMgr::Update(float deltatime)
{
	scenes[(int)currentScene]->Update(deltatime);
}

void SceneMgr::LateUpdate(float deltatime)
{
	scenes[(int)currentScene]->LateUpdate(deltatime);
}

void SceneMgr::onPreDraw()
{
	scenes[(int)currentScene]->OnPreDraw();
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	onPreDraw();
	scenes[(int)currentScene]->Draw(window);
	onPostDraw();
}

void SceneMgr::onPostDraw()
{
	scenes[(int)currentScene]->OnPostDraw();

	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}
}
