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

	void SetPosition(const sf::Vector2f& pos) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& neworigin) override;

	void SetFlipX(bool flipX) override;
	void SetFlipY(bool flipY) override;

	void Init() override;
	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void Draw(sf::RenderTexture& texture);
};

