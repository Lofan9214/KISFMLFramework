#pragma once
class Utils
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
	static void Init();

	static float RandomRange(float min, float max);
	static int RandomRange(int min, int max);
	static float RandomValue(); // 0.f ~ 1.f
	static sf::Vector2f RandomOnUnitCircle();
	static sf::Vector2f RandomInUnitCircle();

#pragma endregion

#pragma region ��Ÿ

	static float Clamp(float value, float min, float max);

#pragma endregion

};

