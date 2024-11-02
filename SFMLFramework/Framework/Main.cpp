#include "stdafx.h"
#include "SceneMgr.h"

int main()
{
	FRAMEWORK.Init(1920,1080,"SFML works!");
	FRAMEWORK.Do();
	FRAMEWORK.Release();
	return 0;

	sf::FloatRect ss;

#pragma region Init
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	ResourceMgr<sf::Texture>::Instance().Load("graphics/player.png");
	sf::Sprite player;
	player.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));
#pragma endregion Init
#pragma region Do
	
#pragma endregion Init

	return 0;
}