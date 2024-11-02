#include "stdafx.h"

GameObject::GameObject(const std::string& name)
	:name(name), originpreset(Origins::TL), origin(0.f, 0.f), scale(1.f, 1.f)
{
}

void GameObject::setOrigin(Origins preset)
{
	originpreset = preset;
	origin = { 0.f, 0.f };
}

void GameObject::setFlipX(bool flipx)
{
	bFlipX = flipx;
	if ((bFlipX && scale.x > 0)
		|| (!bFlipX && scale.x < 0))
	{
		scale.x = -scale.x;
	}
}

void GameObject::setFlipY(bool flipy)
{
	bFlipY = flipy;
	if ((bFlipY && scale.y > 0)
		|| (!bFlipY && scale.y < 0))
	{
		scale.y = -scale.y;
	}
}

void GameObject::init()
{
}

void GameObject::release()
{
}

void GameObject::reset()
{
}

void GameObject::update(float dt)
{
}

void GameObject::draw(sf::RenderWindow& window)
{
}
