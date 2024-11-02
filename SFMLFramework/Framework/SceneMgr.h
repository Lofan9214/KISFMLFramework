#pragma once
#include "Scene.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend Singleton<SceneMgr>;
protected:
	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::Dev1;
	SceneIds currentScene;
	SceneIds nextScene = SceneIds::None;


	SceneMgr() = default;
	virtual ~SceneMgr() = default;

	void onPreDraw();
	void onPostDraw();

	SceneMgr(const SceneMgr&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;
public:
	void init();
	void release();

	Scene* getCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds getCurrentSceneId() const { return currentScene; }
	void changeScene(SceneIds id);

	void update(float deltatime);
	void lateUpdate(float deltatime);

	void draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())