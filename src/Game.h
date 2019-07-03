#pragma once

#include <vector>

#include "Entity.h"

class Game
{
private:
	std::vector<Entity*>* m_entities;
	sf::Window* m_window;
	static Game* m_instance;

public:
	Game(sf::Window* window);
	static Game* instance();

	void addEntity(Entity *entity);
	void removeEntity(Entity *entity);
	const std::vector<Entity*>* getEntities();
	sf::Window* getWindow();
};

