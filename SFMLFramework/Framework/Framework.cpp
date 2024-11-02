#include "stdafx.h"

void Framework::Init(int width, int height, const std::string& name)
{
	window.create(sf::VideoMode(width, height), name);

	Utils::Init();
	InputMgr::Init();
	SCENE_MGR.Init();
}

void Framework::Do()
{
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		realDeltaTime = deltaTime = dt.asSeconds();
		deltaTime *= timeScale;
		realTime += realDeltaTime;
		time += deltaTime;

#pragma region 이벤트 루프
		InputMgr::Clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			InputMgr::UpdateEvent(event);
		}
#pragma endregion 이벤트 루프

#pragma region 업데이트
		InputMgr::Update(deltaTime);
		SCENE_MGR.Update(deltaTime);
		SCENE_MGR.LateUpdate(deltaTime);

#pragma endregion 업데이트

#pragma region 드로우
		window.clear();
		SCENE_MGR.Draw(window);
		window.display();
#pragma endregion 드로우
	}
}

void Framework::Release()
{
	SCENE_MGR.Release();

}