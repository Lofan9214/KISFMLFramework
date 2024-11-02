#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::init()
{

	Scene::init();
}

void SceneDev1::enter()
{
	Scene::enter();

	setStatus(Status::Awake);
}

void SceneDev1::exit()
{
	std::cout << "SceneDev1::exit()" << std::endl;

	Scene::exit();
}

void SceneDev1::update(float dt)
{
	Scene::update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.changeScene(SceneIds::Dev2);
	}

	switch (currentStatus)
	{
	case SceneDev1::Status::Awake:
		updateAwake(dt);
		break;
	case SceneDev1::Status::InGame:
		updateInGame(dt);
		break;
	case SceneDev1::Status::GameOver:
		updateGameOver(dt);
		break;
	case SceneDev1::Status::Pause:
		updatePause(dt);
		break;
	}
}

void SceneDev1::draw(sf::RenderWindow& window)
{
	Scene::draw(window);
}

void SceneDev1::setStatus(Status newStatus)
{
	Status prevStatus = currentStatus;
	currentStatus = newStatus;

	switch (currentStatus)
	{
	case SceneDev1::Status::Awake:
		break;
	case SceneDev1::Status::InGame:
		break;
	case SceneDev1::Status::GameOver:
		break;
	case SceneDev1::Status::Pause:
		break;
	}
}

void SceneDev1::updateAwake(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		setStatus(Status::InGame);
	}
}

void SceneDev1::updateInGame(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		setStatus(Status::Pause);
		return;
	}
}

void SceneDev1::updateGameOver(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		setStatus(Status::InGame);
	}
}

void SceneDev1::updatePause(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		setStatus(Status::InGame);
		return;
	}
}