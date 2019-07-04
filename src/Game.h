#pragma once

#include <vector>

#include "Entity.h"

namespace nge {

    class Game {
    private:
        std::vector<Entity *> *m_entities;
        sf::Window *m_window;
        static Game *m_instance;

    public:
        explicit Game(sf::Window *window = nullptr);

        static Game *instance();

        void addEntity(Entity *entity);

        void removeEntity(Entity *entity);

        const std::vector<Entity *> *getEntities() const;

        sf::Window *getWindow() const;

        void setWindow(sf::Window* window);
    };

}