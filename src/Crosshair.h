#pragma once

#include <SFML/System.hpp>

#include "Entity.h"

namespace nge {

    class Crosshair :
            public Entity {
    public:
        explicit Crosshair(const sf::String& spritePath);

        void init() override;

        void update(sf::Time &dt) override;

        std::vector<sf::Drawable *> draw() override;

        void destroyed() override;

    private:
        sf::Texture *m_texture;
        sf::Sprite *m_sprite;
        float m_x{}, m_y{};
    };

}