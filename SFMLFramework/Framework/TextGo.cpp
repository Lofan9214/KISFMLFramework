#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string& fontId, const std::string& name)
	:fontId(fontId),GameObject(name)
{
}

void TextGo::setOrigin(Origins preset)
{
	originpreset = preset;
	origin = Utilities::SetOrigin(text, preset);
}

void TextGo::setOrigin(const sf::Vector2f& neworigin)
{
	originpreset = Origins::Custom;
	origin = neworigin;
	text.setOrigin(neworigin);
}

void TextGo::setString(const std::string& newtext)
{
	text.setString(newtext);
	setOrigin(originpreset);
}

void TextGo::setCharSize(unsigned int iSize)
{
	text.setCharacterSize(iSize);
}

void TextGo::setTextColor(sf::Color color)
{
	text.setFillColor(color);
}

void TextGo::setPosition(const sf::Vector2f& pos)
{
	GameObject::setPosition(pos);
	text.setPosition(pos);
}

void TextGo::reset()
{
	auto& fontResMgr = ResourceMgr<sf::Font>::Instance();
	text.setFont(fontResMgr.Get(fontId));
	if (originpreset != Origins::Custom)
	{
		setOrigin(originpreset);
	}
}

void TextGo::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
	window.draw(text);
}
