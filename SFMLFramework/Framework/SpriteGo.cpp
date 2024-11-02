#include "stdafx.h"
#include "SpriteGo.h"

void SpriteGo::reset()
{
	sprite.setTexture(ResourceMgr<sf::Texture>::Instance().Get(textureId));
	sprite.setScale(scale);
	setOrigin(originpreset);
}

SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	:textureId(texId), GameObject(name)
{
}

void SpriteGo::setOrigin(Origins preset)
{
	if (preset < Origins::Custom)
	{
		originpreset = preset;
		origin = Utilities::SetOrigin(sprite, preset);
	}
}

void SpriteGo::setOrigin(const sf::Vector2f& neworigin)
{
	originpreset = Origins::Custom;
	sprite.setOrigin(neworigin);
}

void SpriteGo::setFlipX(bool flipX)
{
	GameObject::setFlipX(flipX);
	sprite.setScale(scale);
}

void SpriteGo::setFlipY(bool flipY)
{
	GameObject::setFlipY(flipY);
	sprite.setScale(scale);
}

void SpriteGo::setPosition(const sf::Vector2f& pos)
{
	GameObject::setPosition(pos);
	sprite.setPosition(pos);
}

void SpriteGo::init()
{
}

void SpriteGo::release()
{
}

void SpriteGo::update(float dt)
{
	sprite.setPosition(position);

	GameObject::update(dt);
}

void SpriteGo::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
	window.draw(sprite);
}
