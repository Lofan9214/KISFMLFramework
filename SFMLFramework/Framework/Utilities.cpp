#include "stdafx.h"
#include "Utilities.h"

std::mt19937 Utilities::generator;
const float Utilities::PI = acosf(-1);

sf::Vector2f Utilities::SetOrigin(sf::Sprite& obj, Origins preset)
{
	return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utilities::SetOrigin(sf::Text& obj, Origins preset)
{
	return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utilities::SetOrigin(sf::Shape& obj, Origins preset)
{
	return SetOrigin(obj,preset, obj.getLocalBounds());
}

sf::Vector2f Utilities::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect& localbound)
{
	sf::Vector2f newOrigin;

	newOrigin.x = localbound.left + localbound.width * ((int)preset % 3) * 0.5f;
	newOrigin.y = localbound.top + localbound.height * ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigin);

	return newOrigin;
}

void Utilities::init()
{
	std::random_device rd;
	generator.seed(rd());
}

float Utilities::randFloatRange(float min, float max)
{
	std::uniform_real_distribution<> dist(min, max);
	return dist(generator);
}

int Utilities::randIntRange(int min, int max)
{
	std::uniform_int_distribution<> dist(min, max);
	return dist(generator);
}

float Utilities::randPercent()
{
	std::uniform_real_distribution<> dist(0.f, 1.f);
	return dist(generator);
}

sf::Vector2f Utilities::randOnCircle()
{
	float rad = randFloatRange(0.f, PI * 2.f);
	return sf::Vector2f(std::cosf(rad), std::sinf(rad));
}

sf::Vector2f Utilities::randInCircle()
{
	return randOnCircle() * randPercent();
}

float Utilities::Clamp(float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}
	if (value > max)
	{
		return max;
	}
	return value;
}

