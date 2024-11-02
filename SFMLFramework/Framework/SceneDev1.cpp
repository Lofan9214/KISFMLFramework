#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{

	Scene::Init();
}

void SceneDev1::Enter()
{
	Scene::Enter();

	setStatus(Status::Awake);
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::exit()" << std::endl;

	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
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

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
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