#include "stdafx.h"

void Framework::Init(int width, int height, const std::string& name)
{
	window.create(sf::VideoMode(width, height), name);

	Utilities::init();

	SCENE_MGR.init();
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

#pragma region �̺�Ʈ ����
		InputMgr::Clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			InputMgr::UpdateEvent(event);
		}
#pragma endregion �̺�Ʈ ����

#pragma region ������Ʈ
		SCENE_MGR.update(deltaTime);
		SCENE_MGR.lateUpdate(deltaTime);

#pragma endregion ������Ʈ

#pragma region ��ο�
		window.clear();
		SCENE_MGR.draw(window);
		window.display();
#pragma endregion ��ο�
	}
}

void Framework::Release()
{
	SCENE_MGR.release();

}