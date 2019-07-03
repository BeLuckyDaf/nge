#include "Game.h"

Game* Game::instance;

Game::Game()
{
	instance = nullptr;
	entities = nullptr;

	if (!instance) 
	{
		instance = this;
		entities = new std::vector<Entity*>();
	}
	else 
	{
		std::printf("Could not change game instance. Instance already exists.\n");
	}
}

Game* Game::Instance()
{
	if (instance) return instance;
	else return nullptr;
}

void Game::AddEntity(Entity* entity)
{
	entities->push_back(entity);
}

void Game::RemoveEntity(Entity* entity)
{
	
}

const std::vector<Entity*>* Game::GetEntities()
{
	return entities;
}
