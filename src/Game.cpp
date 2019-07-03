#include "Game.h"

Game* Game::m_instance;

Game::Game(sf::Window* window)
{
    if (window == nullptr)
    {
        std::printf("Window cannot be null.\n");
    }

	m_instance = nullptr;
	m_entities = nullptr;
	m_window = window;

	if (!m_instance)
	{
		m_instance = this;
		m_entities = new std::vector<Entity*>();
	}
	else 
	{
		std::printf("Could not change game m_instance. instance already exists.\n");
	}
}

Game* Game::instance()
{
	if (m_instance) return m_instance;
	else return nullptr;
}

void Game::addEntity(Entity *entity)
{
	m_entities->push_back(entity);
}

void Game::removeEntity(Entity *entity)
{
	
}

const std::vector<Entity*>* Game::getEntities()
{
	return m_entities;
}

sf::Window *Game::getWindow() {
    return m_window;
}
