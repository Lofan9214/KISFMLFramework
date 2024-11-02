#pragma once

class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo() = default;
	~SpriteGo() = default;

	SpriteGo(const std::string& texId, const std::string& name = "");
	void setTextureId(const std::string& id) { textureId = id; }

	void setPosition(const sf::Vector2f& pos) override;

	void setOrigin(Origins preset) override;
	void setOrigin(const sf::Vector2f& neworigin) override;

	void setFlipX(bool flipX) override;
	void setFlipY(bool flipY) override;

	void init() override;
	void release() override;

	void reset() override;

	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};

