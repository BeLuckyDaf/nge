#pragma once

#include "Entity.h"

class Circle :
	public Entity
{
public:
	Circle(float x, float y, float radius);

	void init();
	void update(sf::Time &dt);
	std::vector<sf::Drawable*> draw();

private:
    sf::CircleShape* m_shape;
    sf::Texture* m_texture;
    sf::Sprite* m_sprite;
    float m_x, m_y;
};

