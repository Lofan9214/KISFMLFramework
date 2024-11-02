#include "stdafx.h"
#include "SceneDev1.h"
#include "SceneDev2.h"


void SceneMgr::init()
{
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());

	for (auto scene : scenes)
	{
		scene->init();
	}
	currentScene = startScene;
	scenes[(int)currentScene]->enter();
}

void SceneMgr::release()
{
	for (auto scene : scenes)
	{
		scene->release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::changeScene(SceneIds id)
{
	nextScene = id;

}

void SceneMgr::update(float deltatime)
{
	scenes[(int)currentScene]->update(deltatime);
}

void SceneMgr::lateUpdate(float deltatime)
{
	scenes[(int)currentScene]->lateUpdate(deltatime);
}

void SceneMgr::onPreDraw()
{
	scenes[(int)currentScene]->onPreDraw();
}

void SceneMgr::draw(sf::RenderWindow& window)
{
	onPreDraw();
	scenes[(int)currentScene]->draw(window);
	onPostDraw();
}

void SceneMgr::onPostDraw()
{
	scenes[(int)currentScene]->onPostDraw();

	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->enter();
	}
}
