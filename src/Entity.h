#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	virtual void Init();
	virtual void Update(sf::Time& dt);
	virtual std::vector<sf::Drawable*> Draw();
	virtual void Destroyed();
};

