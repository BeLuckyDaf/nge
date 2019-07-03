#include "Entity.h"
#include "Game.h"

Entity::Entity()
{
}

void Entity::Init()
{
	Game* game = Game::Instance();
	if (game != nullptr) {
		game->AddEntity(this);
	}
	else {
		std::printf("Could not add entity. No game found.\n");
	}
}

void Entity::Update(sf::Time& dt)
{
}

std::vector<sf::Drawable*> Entity::Draw()
{
	return std::vector<sf::Drawable*>();
}

void Entity::Destroyed()
{
}
