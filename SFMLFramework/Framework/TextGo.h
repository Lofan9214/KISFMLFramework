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

	void Reset() override;
	void Draw(sf::RenderWindow& window) override;

	TextGo(const std::string& fontId, const std::string& name = "");

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& neworigin) override;


	void SetPosition(const sf::Vector2f& pos) override;

	void SetTextString(const std::string& newtext);
	void SetCharSize(unsigned int iSize);
	void SetFillColor(sf::Color color);
};

