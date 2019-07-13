#include <memory>

#include <SFML/Graphics.hpp>
#include <sstream>
#include <memory>

#include "Game.h"
#include "Crosshair.h"

using namespace nge;

int main() {
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Norfoe Game Engine");
    sf::Clock deltaClock;

    window->setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);

    Game game(window);
    auto crosshair = std::make_shared<Crosshair>("Assets/crosshair.png");
    auto font = std::make_shared<sf::Font>();

    font->loadFromFile("Assets/Ubuntu-R.ttf");
    auto fpsLabel = std::make_shared<sf::Text>("", *font);
    fpsLabel->setFillColor(sf::Color::White);

    /* ==== INIT ==== */

    // Call init for each entity
    for (auto entity : *game.getEntities()) {
        entity->init();
    }


    float fpsTimer = 0;
    int fpsCount = 0;
    while (window->isOpen()) {
        sf::Time dt = deltaClock.restart();

        if (fpsTimer < 1) {
            fpsTimer += dt.asSeconds();
            fpsCount++;
        }
        else {
            std::ostringstream oss;
            oss << "FPS: " << fpsCount;
            fpsLabel->setString(oss.str());
            fpsCount = 0;
            fpsTimer = 0;
        }

        /* ==== EVENTS AND INPUT ==== */

        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window->close();
            }
        }

        /* ==== UPDATE ==== */

        // Call update for each entity
        for (auto entity : *game.getEntities()) {
            entity->update(dt);
        }

        window->clear();

        /* ==== DRAWING ==== */

        // Call draw for each entity
        for (auto entity : *game.getEntities()) {
            auto drawables = entity->draw();
            for (auto drawable : drawables) {
                window->draw(*drawable);
            }
        }

        window->draw(*fpsLabel);

        window->display();
    }

    /* ==== DESTROYING ==== */

    // Call destroyed for each entity
    for (auto entity : *game.getEntities()) {
        entity->destroyed();
    }

    return 0;
}