#include "Game.h"

namespace nge {

    Game *Game::m_instance;

    Game::Game(sf::Window *window) {
        m_instance = nullptr;
        m_entities = nullptr;
        m_window = window;

        if (!m_instance) {
            m_instance = this;
            m_entities = new std::vector<Entity *>();
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

    }

    const std::vector<Entity *> *Game::getEntities() const {
        return m_entities;
    }

    sf::Window *Game::getWindow() const {
        return m_window;
    }

    void Game::setWindow(sf::Window* window) {
        m_window = window;
    }

}