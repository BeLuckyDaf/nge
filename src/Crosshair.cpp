#include "Crosshair.h"
#include "Game.h"

namespace nge {

    Crosshair::Crosshair(const sf::String& spritePath) {
        m_texture = new sf::Texture();
        m_texture->loadFromFile(spritePath.toAnsiString());
        m_sprite = new sf::Sprite(*m_texture);
        m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2, m_sprite->getLocalBounds().height / 2);
    }

    void Crosshair::update(sf::Time &dt) {
        Entity::update(dt);

        // Follow the cursor
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*Game::instance()->getWindow());
        m_sprite->setPosition(mousePosition.x, mousePosition.y);
    }

    std::vector<sf::Drawable *> Crosshair::draw() {
        std::vector<sf::Drawable *> result;
        result.push_back(m_sprite);

        return result;
    }

    void Crosshair::destroyed() {
        Entity::destroyed();
    }

    void Crosshair::init() {
        Entity::init();
    }

}