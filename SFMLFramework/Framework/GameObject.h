#pragma once
class GameObject
{
protected:
	std::string name;
	bool active = true;
	sf::Vector2f position;
	Origins originpreset;
	sf::Vector2f origin;
	sf::Vector2f scale;

	bool bFlipX = false;
	bool bFlipY = false;

	//복사생성자, 대입연산자 막기
public:
	SortingLayers sortinglayer = SortingLayers::Default;
	int sortingOrder = 0;

	GameObject(const std::string& name = "");
	virtual ~GameObject() = default;

	const std::string& getName() { return name; }
	void setName(const std::string& iname) { name = iname; }

	bool isActive() const { return active; }
	void setActive(bool bActive) { active = bActive; }

	sf::Vector2f getPosition() const { return position; }
	virtual void setPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f getOrigin() const { return origin; }
	virtual void setOrigin(Origins preset);
	virtual void setOrigin(const sf::Vector2f& neworigin)
	{
		origin = neworigin;
		originpreset = Origins::Custom;
	}

	sf::Vector2f getScale() const { return scale; }
	virtual void setScale(const sf::Vector2f& iscale) { scale = iscale; }

	virtual bool getFlipX() const { return bFlipX; }
	virtual void setFlipX(bool flipx);
	virtual bool getFlipY() const { return bFlipY; }
	virtual void setFlipY(bool flipy);

	virtual void init();
	virtual void release();

	virtual void reset();

	virtual void update(float dt);
	virtual void draw(sf::RenderWindow& window);

};

struct DrawOrderComparer
{
	bool operator()(GameObject* a, GameObject* b) const
	{
		if (a->sortinglayer != b->sortinglayer)
		{
			return a->sortinglayer > b->sortinglayer;
		}
		return a->sortingOrder > b->sortingOrder;
	}
};