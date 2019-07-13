#include <utility>

#include <utility>

#include <utility>

#include "Game.h"

namespace nge {

    Game *Game::m_instance;

    Game::Game(std::shared_ptr<sf::RenderWindow> window) {
        m_instance = nullptr;
        m_entities = nullptr;
        m_window = std::move(window);

        if (!m_instance) {
            m_instance = this;
            m_entities = std::make_shared<std::vector<Entity*>>();
        } else {
            std::printf("Could not change game m_instance. instance already exists.\n");
        }
    }

    Game *Game::instance() {
        if (m_instance) return m_instance;
        else return nullptr;
    }

    void Game::addEntity(Entity *entity) {
        m_entities->push_back(entity);
    }

    void Game::removeEntity(Entity *entity) {
        // TODO: implement removeEntity
    }

    std::shared_ptr<std::vector<Entity*>> Game::getEntities() const {
        return m_entities;
    }

    std::shared_ptr<sf::RenderWindow> Game::getWindow() const {
        return m_window;
    }

    void Game::setWindow(std::shared_ptr<sf::RenderWindow> window) {
        m_window = std::move(window);
    }

}