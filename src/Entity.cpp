#include "Entity.h"
#include "Game.h"

namespace nge {

    Entity::Entity() {
        Game *game = Game::instance();
        if (game != nullptr) {
            game->addEntity(this);
        } else {
            std::fprintf(stderr, "Could not add entity. No game found.\n");
        }
    }

    void Entity::init() {
        printf("called\n");
    }

    void Entity::update(sf::Time &dt) {
    }

    std::vector<sf::Drawable *> Entity::draw() {
        return std::vector<sf::Drawable *>();
    }

    void Entity::destroyed() {
        Game *game = Game::instance();
        if (game != nullptr) {
            game->removeEntity(this);
        } else {
            std::fprintf(stderr, "Could not remove entity. No game found.\n");
        }
    }

}
