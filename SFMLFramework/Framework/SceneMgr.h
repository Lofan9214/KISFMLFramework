#pragma once
#include "Scene.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend Singleton<SceneMgr>;
protected:
	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::Game;
	SceneIds currentScene;
	SceneIds nextScene = SceneIds::None;


	SceneMgr() = default;
	virtual ~SceneMgr() = default;

	void onPreDraw();
	void onPostDraw();

	SceneMgr(const SceneMgr&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;
public:
	void Init();
	void Release();

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void ChangeScene(SceneIds id);

	void Update(float deltatime);
	void LateUpdate(float deltatime);

	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())