#pragma once

class Scene
{
protected:
	const SceneIds id;
	std::list<GameObject*> gameObjects;

	std::list<GameObject*> addGameObjs;
	std::list<GameObject*> removeGameObjs;
	
	std::list<std::list<GameObject*>> drawObjects;
	std::list<sf::View*> drawView;

	bool gameObjectsChanged = false;

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void LateUpdate(float dt);

	virtual void OnPreDraw();
	virtual void Draw(sf::RenderWindow& window);
	virtual void OnPostDraw();

	template<typename T>
	T* AddGo(T* obj)
	{
		gameObjectsChanged = true;
		addGameObjs.push_back(obj);
		return obj;
	}

	virtual void RemoveGo(GameObject* obj);

	template<typename T>
	void RemoveGo(std::list<T*> lstobj)
	{
		gameObjectsChanged = true;
		for (auto obj : lstobj)
		{
			removeGameObjs.push_back(obj);
		}
	}

	virtual GameObject* FindGo(const std::string& name);
	virtual int FindGoAll(const std::string& name, std::list<GameObject*>& list);

	void ApplyAddGo();
	void ApplyRemoveGo();
	void SortDrawObject();
};

