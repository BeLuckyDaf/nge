#include <SFML/Graphics.hpp>
#include <sstream>

#include "Game.h"
#include "Crosshair.h"

using namespace nge;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Norfoe Game Engine");
    sf::Clock deltaClock;

    //window.setFramerateLimit(30);
    //window.setVerticalSyncEnabled(true);

    Game game(&window);
    Crosshair crosshair("Assets/crosshair.png");

    sf::Font *font = new sf::Font;
    font->loadFromFile("Assets/Ubuntu-R.ttf");
    sf::Text text("", *font);
    text.setFillColor(sf::Color::White);

    /* ==== INIT ==== */

    // Call init for each entity
    for (auto entity : *game.getEntities()) {
        entity->init();
    }

    int fpsCounter = 0;
    float deltaFpsSeconds = 0;
    float fps = 1;

    while (window.isOpen()) {
        sf::Time dt = deltaClock.restart();

        // Showing framerate
        if (fpsCounter < fps/10) {
            fpsCounter++;
            deltaFpsSeconds += dt.asSeconds();
        }
        else {
            std::ostringstream oss;
            fps = (fpsCounter)/deltaFpsSeconds;
            oss << "FPS: " << fps;
            text.setString(oss.str());
            fpsCounter = 0;
            deltaFpsSeconds = 0;
        }

        /* ==== EVENTS AND INPUT ==== */

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window.close();
            }
        }

        /* ==== UPDATE ==== */

        // Call update for each entity
        for (auto entity : *game.getEntities()) {
            entity->update(dt);
        }

        window.clear();

        /* ==== DRAWING ==== */

        // Call draw for each entity
        for (auto entity : *game.getEntities()) {
            auto drawables = entity->draw();
            for (auto drawable : drawables) {
                window.draw(*drawable);
            }
        }

        window.draw(text);

        window.display();
    }

    /* ==== DESTROYING ==== */

    // Call destroyed for each entity
    for (auto entity : *game.getEntities()) {
        entity->destroyed();
    }

    return 0;
}