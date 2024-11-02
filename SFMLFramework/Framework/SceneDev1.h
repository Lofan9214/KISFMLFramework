#pragma once
#include "Scene.h"

class SceneDev1 :
	public Scene
{
public:
	enum class Status
	{
		Awake,
		InGame,
		GameOver,
		Pause,
	};

protected:
	Status currentStatus = Status::Awake;

public:
	SceneDev1();
	~SceneDev1() = default;
	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	void setStatus(Status newStatus);
	void updateAwake(float dt);
	void updateInGame(float dt);
	void updateGameOver(float dt);
	void updatePause(float dt);
};

