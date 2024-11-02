#include "stdafx.h"
#include "SceneGame.h"
#include "BallGo.h"
#include "BatGo.h"
#include "UiScore.h"
#include "UiMessage.h"
#include "SpriteGo.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

void SceneGame::Init()
{
	bg = AddGo(new SpriteGo("bg.jpg", "name"));
	ball = AddGo(new BallGo("Ball"));
	ball2 = AddGo(new BallGo("Ball"));
	bat = AddGo(new BatGo("Bat"));
	uiScore = AddGo(new UiScore("fonts/KOMIKAP_.ttf"));
	uiMessage = AddGo(new UiMessage("fonts/KOMIKAP_.ttf"));
	minimap = sf::CircleShape(50.f);
	auto size = FRAMEWORK.GetWindowSizef();

	bat->SetPosition({ size.x * 0.5f,size.y - 50.f });

	ball->SetBat(bat);
	ball2->SetBat(bat);
	uiScore->SetPosition({ size.x * 0.5f, 100.f });
	uiMessage->SetPosition({ size.x * 0.5f, size.y * 0.5f });

	Scene::Init();
}

void SceneGame::Enter()
{
	TEXTURE_MGR.Load("bg.jpg");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	FRAMEWORK.SetTimeScale(1.f);

	Scene::Enter();

	isBallFired = false;
}

void SceneGame::Exit()
{
	TEXTURE_MGR.Unload("bg.jpg");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (!isBallFired)
	{
		ball->SetPosition(bat->GetPosition());
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		isBallFired = true;
		float angle = Utils::RandomRange(Utils::PI, Utils::PI * 2.f);
		ball->Fire({ cosf(angle),sinf(angle) }, 500.f);
	}

	if (ball->GetHitBat())
	{
		ball->ResetHitBat();
		uiScore->AddScore(1);
	}
	if (ball->GetHitBottom())
	{
		FRAMEWORK.SetTimeScale(0.f);
		ball->ResetHitBottom();
		uiMessage->SetActive(true);
	}

	float a = 50.f;
	sf::Vector2f center = FRAMEWORK.GetWindowSizef() * 0.5f;
	sf::Vector2f LemniscatePos = { a * cosf(FRAMEWORK.GetTime()) / (1 + sinf(FRAMEWORK.GetTime()) * sinf(FRAMEWORK.GetTime())),a * sinf(FRAMEWORK.GetTime()) * cosf(FRAMEWORK.GetTime()) / (1 + sinf(FRAMEWORK.GetTime()) * sinf(FRAMEWORK.GetTime())) };
	ball2->SetPosition(center + LemniscatePos);

	if (InputMgr::GetKeyDown(sf::Keyboard::F5))
	{
		SCENE_MGR.ChangeScene(SCENE_MGR.GetCurrentSceneId());
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

	sf::RenderTexture rt;
	rt.create(120, 120);
	rt.clear({ 0,0,0,0 });
	sf::View testview({ 0,0,120,120 });
	//testview.setViewport({ 0.75,0.1,0.2,0.2 });
	testview.zoom(0.5f);
	testview.setCenter({ minimap.getPosition().x+50.f,minimap.getPosition().y+50.f });

	rt.setView(testview);

	sf::Vector2f posminimap = { InputMgr::GetMousePositionf().x - minimap.getPosition().x - 50.f,InputMgr::GetMousePositionf().y - minimap.getPosition().y-50.f };

	posminimap *= FRAMEWORK.GetDeltaTime()*5.f;
	float a = 0.05f;
	sf::Vector2f LemniscatePos = { a * cosf(FRAMEWORK.GetTime()) / (1 + sinf(FRAMEWORK.GetTime()) * sinf(FRAMEWORK.GetTime())),a * sinf(FRAMEWORK.GetTime()) * cosf(FRAMEWORK.GetTime()) / (1 + sinf(FRAMEWORK.GetTime()) * sinf(FRAMEWORK.GetTime())) };
	posminimap += minimap.getPosition();
	bg->Draw(rt);
	rt.display();
	posminimap += LemniscatePos;
	minimap.setPosition(posminimap);
	minimap.setTexture(&rt.getTexture());
	window.draw(minimap);

}