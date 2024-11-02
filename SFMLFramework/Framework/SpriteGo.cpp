#include "stdafx.h"
#include "SpriteGo.h"

void SpriteGo::Reset()
{
	sprite.setTexture(ResourceMgr<sf::Texture>::Instance().Get(textureId));
	sprite.setScale(scale);
	SetOrigin(originPreset);
}

SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	:textureId(texId), GameObject(name)
{
}

void SpriteGo::SetOrigin(Origins preset)
{
	if (preset < Origins::Custom)
	{
		originPreset = preset;
		origin = Utils::SetOrigin(sprite, preset);
	}
}

void SpriteGo::SetOrigin(const sf::Vector2f& neworigin)
{
	originPreset = Origins::Custom;
	sprite.setOrigin(neworigin);
}

void SpriteGo::SetFlipX(bool flipX)
{
	GameObject::SetFlipX(flipX);
	sprite.setScale(scale);
}

void SpriteGo::SetFlipY(bool flipY)
{
	GameObject::SetFlipY(flipY);
	sprite.setScale(scale);
}

void SpriteGo::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void SpriteGo::Init()
{
}

void SpriteGo::Release()
{
}

void SpriteGo::Update(float dt)
{
	sprite.setPosition(position);

	GameObject::Update(dt);
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}

void SpriteGo::Draw(sf::RenderTexture& texture)
{
	texture.draw(sprite);
}
