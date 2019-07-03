#include "Circle.h"

Circle::Circle(float x, float y, float radius)
{
	shape = new sf::CircleShape(radius);
	sf::Color fillColor(255, 0, 0);
	shape->setFillColor(fillColor);
	shape->setOrigin(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2);
	this->x = x;
	this->y = y;
}

void Circle::Init()
{
}

void Circle::Update(sf::Time& dt)
{
	x += 1.f;
	shape->setPosition(x, y);
}

std::vector<sf::Drawable*> Circle::Draw()
{
	std::vector<sf::Drawable*> result;
	result.push_back(shape);

	return result;
}
