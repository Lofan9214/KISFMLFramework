#pragma once
#include "Scene.h"

class BallGo;
class BatGo;
class UiScore;
class UiMessage;
class SpriteGo;

class SceneGame :
	public Scene
{
protected:
	BallGo* ball;
	BallGo* ball2;
	BatGo* bat;
	UiScore* uiScore;
	UiMessage* uiMessage;
	SpriteGo* bg;
	sf::CircleShape minimap;

	bool isBallFired = false;

public:
	SceneGame();
	virtual ~SceneGame() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

