#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace nge {

    class Entity {
    public:
        Entity();

        virtual void init();

        virtual void update(sf::Time &dt);

        virtual std::vector<sf::Drawable *> draw();

        virtual void destroyed();
    };

}
