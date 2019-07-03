#include "Entity.h"
#include "Game.h"

Entity::Entity()
{
}

void Entity::init()
{
	Game* game = Game::instance();
	if (game != nullptr) {
        game->addEntity(this);
	}
	else {
		std::printf("Could not add entity. No game found.\n");
	}
}

void Entity::update(sf::Time &dt)
{
}

std::vector<sf::Drawable*> Entity::draw()
{
	return std::vector<sf::Drawable*>();
}

void Entity::destroyed()
{
}
