#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace nge {

    class Entity {
    public:
        Entity();
        ~Entity();

        virtual void init();

        virtual void update(sf::Time &dt);

        virtual std::vector<sf::Drawable *> draw() = 0;

        virtual void destroyed();
    };

}
