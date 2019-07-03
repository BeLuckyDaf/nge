#pragma once

#include "Entity.h"

class Circle :
	public Entity
{
public:
	Circle(float x, float y, float radius);
	sf::CircleShape* shape;
	float x, y;

	void Init();
	void Update(sf::Time& dt);
	std::vector<sf::Drawable*> Draw();
};

