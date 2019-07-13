#pragma once

#include <vector>
#include <memory>

#include "Entity.h"

namespace nge {

    class Game {
    private:
        std::shared_ptr<std::vector<Entity*>> m_entities;
        std::shared_ptr<sf::RenderWindow> m_window;
        static Game *m_instance;

    public:
        explicit Game(std::shared_ptr<sf::RenderWindow> window = nullptr);

        static Game *instance();

        void addEntity(Entity *entity);

        void removeEntity(Entity *entity);

        std::shared_ptr<std::vector<Entity*>> getEntities() const;

        std::shared_ptr<sf::RenderWindow> getWindow() const;

        void setWindow(std::shared_ptr<sf::RenderWindow> window);
    };

}