#pragma once

class Scene
{
protected:
	const SceneIds id;
	std::list<GameObject*> gameObjects;

	std::list<GameObject*> addGameObjs;
	std::list<GameObject*> removeGameObjs;

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void init();
	virtual void release();

	virtual void enter();
	virtual void exit();

	virtual void update(float dt);
	virtual void lateUpdate(float dt);

	virtual void onPreDraw();
	virtual void draw(sf::RenderWindow& window);
	virtual void onPostDraw();

	template<typename T>
	T* addGo(T* obj)
	{
		addGameObjs.push_back(obj);
		return obj;
	}

	virtual void removeGo(GameObject* obj);
	template<typename T>
	void removeGo(std::list<T*> lstobj)
	{
		for (auto obj : lstobj)
		{
			removeGameObjs.push_back(obj);
		}
	}
	virtual GameObject* findGo(const std::string& name);
	virtual int FindGoAll(const std::string& name, std::list<GameObject*>& list);

	void applyAddGo();
	void applyRemoveGo();
};

