#pragma once
class Utilities
{
private:

	static std::mt19937 generator;
	

public:
	const static float PI;

#pragma region ������ ����
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Shape& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Transformable& obj, Origins preset,const sf::FloatRect& localbound);

#pragma endregion

#pragma region ����
	static void init();

	static float randFloatRange(float min, float max);
	static int randIntRange(int min, int max);
	static float randPercent();
	static sf::Vector2f randOnCircle();
	static sf::Vector2f randInCircle();

#pragma endregion

#pragma region ��Ÿ

	static float Clamp(float value, float min, float max);

#pragma endregion

};

