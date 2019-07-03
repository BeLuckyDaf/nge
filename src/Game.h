#pragma once

#include <vector>

#include "Entity.h"

class Game
{
private:
	std::vector<Entity*>* entities;
	static Game* instance;

public:
	Game();
	static Game* Instance();

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	const std::vector<Entity*>* GetEntities();
};

