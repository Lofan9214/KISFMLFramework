#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::init()
{
	std::cout << "SceneDev2::init()" << std::endl;

	GameObject* obj = addGo(new SpriteGo("graphics/player.png", "player"));
	GameObject* obj2 = addGo(new TextGo("fonts/KOMIKAP_.ttf", "SceneDev2"));

	obj2->setOrigin(Origins::TL);
	obj2->setPosition({ 100.f, 50.f });
	auto cst = dynamic_cast<TextGo*> (obj2);
	if (cst != nullptr)
		(dynamic_cast<TextGo*> (obj2))->setString("Scenesdkjlsfdkjl");
	Scene::init();
}

void SceneDev2::enter()
{
	std::cout << "SceneDev2::enter()" << std::endl;

	TEXTURE_MGR.Load("graphics/player.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");

	Scene::enter();
}

void SceneDev2::exit()
{
	std::cout << "SceneDev2::exit()" << std::endl;

	Scene::exit();
	TEXTURE_MGR.Unload("graphics/player.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");

}

void SceneDev2::update(float dt)
{
	Scene::update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.changeScene(SceneIds::Dev1);
	}
}

void SceneDev2::draw(sf::RenderWindow& window)
{
	Scene::draw(window);
}
