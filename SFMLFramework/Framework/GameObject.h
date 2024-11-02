#pragma once
class GameObject
{
protected:
	std::string name;
	bool active = true;
	sf::Vector2f position;
	Origins originPreset;
	sf::Vector2f origin;
	sf::Vector2f scale;

	bool bFlipX = false;
	bool bFlipY = false;

	SortingLayers sortingLayer = SortingLayers::Default;
	int sortingOrder = 0;
	int targetView = 0;

	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject() = default;

	const std::string& GetName() { return name; }
	void SetName(const std::string& iname) { name = iname; }

	bool IsActive() const { return active; }
	void SetActive(bool bActive) { active = bActive; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& neworigin)
	{
		origin = neworigin;
		originPreset = Origins::Custom;
	}

	sf::Vector2f GetScale() const { return scale; }
	virtual void SetScale(const sf::Vector2f& iscale) { scale = iscale; }

	virtual bool GetFlipX() const { return bFlipX; }
	virtual void SetFlipX(bool flipx);
	virtual bool GetFlipY() const { return bFlipY; }
	virtual void SetFlipY(bool flipy);

	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	void SetSortingLayer(SortingLayers sortingLayer) { this->sortingLayer = sortingLayer; }
	SortingLayers GetSortingLayer() { return sortingLayer; }

	void SetSortingOrder(int sortingOrder) { this->sortingOrder = sortingOrder; }
	int GetSortingOrder() { return this->sortingOrder; }
};

struct DrawOrderComparer
{
	bool operator()(GameObject* a, GameObject* b) const
	{
		SortingLayers sLA = a->GetSortingLayer();
		SortingLayers sLB = b->GetSortingLayer();
		if (sLA != sLB)
		{
			return sLA > sLB;
		}
		return a->GetSortingOrder() > b->GetSortingOrder();
	}
};