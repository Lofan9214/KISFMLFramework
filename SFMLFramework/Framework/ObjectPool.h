#pragma once

template<typename T>
class ObjectPool
{
private:
	std::list<T*> unused;
	std::list<T*> used;

public:
	ObjectPool(int initSize = 10)
	{
		for (int i = 0;i < initSize;++i)
		{
			auto obj = new T();
			obj->init();
			unused.push_back(obj);
		}
	}

	virtual ~ObjectPool()
	{
		for (auto obj : unused)
		{
			delete obj;
		}
	}

	T* Take()
	{
		if (unused.empty())
		{
			auto obj = new T();
			obj->init();
			obj->reset();
			used.push_back(obj);
			return obj;
		}
		auto obj = unused.front();
		unused.pop_front();
		used.push_back(obj);
		obj->reset();
		return obj;
	}

	void Return(T* obj)
	{
		auto found = std::find(used.begin(), used.end(), obj);
		if (found == used.end())
		{
			std::cout << "ObjectPool : Invailed Obj" << std::endl;
			return;
		}

		used.erase(found);
		obj->setActive(false);
		unused.push_back(obj);
	}

	std::list<T*> Update(float dt)
	{
		std::list<T*> lstremove;
		auto it = used.begin();
		while (it != used.end())
		{
			if (!(*it)->isActive())
			{
				unused.push_back(*it);
				lstremove.push_back(*it);
				it = used.erase(it);
			}
			else
			{
				++it;
			}
		}
		return lstremove;
	}

	void Reset()
	{
		auto it = used.begin();
		while (it != used.end())
		{
			(*it)->reset();
			unused.push_back(*it);
			it = used.erase(it);
		}
	}

	void Release()
	{
		
	}

	std::list<T*>& getListUsing() { return used; }
	std::list<T*>& getListUnusing() { return unused; }
};