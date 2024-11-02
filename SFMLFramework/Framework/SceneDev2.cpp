#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	std::cout << "SceneDev2::init()" << std::endl;

	GameObject* obj = AddGo(new SpriteGo("graphics/player.png", "player"));
	GameObject* obj2 = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "SceneDev2"));

	obj2->SetOrigin(Origins::TL);
	obj2->SetPosition({ 100.f, 50.f });
	auto cst = dynamic_cast<TextGo*> (obj2);
	if (cst != nullptr)
		(dynamic_cast<TextGo*> (obj2))->SetTextString("Scenesdkjlsfdkjl");
	Scene::Init();
}

void SceneDev2::Enter()
{
	std::cout << "SceneDev2::enter()" << std::endl;

	TEXTURE_MGR.Load("graphics/player.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");

	Scene::Enter();
}

void SceneDev2::Exit()
{
	std::cout << "SceneDev2::exit()" << std::endl;

	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/player.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");

}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
