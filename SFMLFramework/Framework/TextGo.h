#pragma once
#include "GameObject.h"
class TextGo :
    public GameObject
{
protected:
    sf::Text text;
    std::string fontId;
	
	TextGo(const TextGo&) = delete;
	TextGo& operator=(const TextGo&) = delete;

public:
	TextGo() = default;
	~TextGo() = default;

	void reset() override;
	void draw(sf::RenderWindow& window) override;

	TextGo(const std::string& fontId, const std::string& name = "");

	void setOrigin(Origins preset) override;
	void setOrigin(const sf::Vector2f& neworigin) override;


	void setPosition(const sf::Vector2f& pos) override;

	void setString(const std::string& newtext);
	void setCharSize(unsigned int iSize);
	void setTextColor(sf::Color color);
};

