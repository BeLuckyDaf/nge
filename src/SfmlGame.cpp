#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Circle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setVerticalSyncEnabled(true);

	Game game;
	//Circle circle1(0.f, 25.f, 15.f);
	//Circle circle2(0.f, 300.f, 100.f);
	Circle circle3(0.f, 600.f, 50.f);

	//game.AddEntity(&circle1);
	//game.AddEntity(&circle2);
	game.AddEntity(&circle3);

	int w, s, d, a, e, q;
	w = s = d = a = e = q = 0;

	for (auto entity : *game.GetEntities()) {
		entity->Init();
	}

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Time dt = deltaClock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::W) w = 1;
				if (event.key.code == sf::Keyboard::S) s = 1;
				if (event.key.code == sf::Keyboard::D) d = 1;
				if (event.key.code == sf::Keyboard::A) a = 1;

				if (event.key.code == sf::Keyboard::E) e = 1;
				if (event.key.code == sf::Keyboard::Q) q = 1;

				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::W) w = 0;
				if (event.key.code == sf::Keyboard::S) s = 0;
				if (event.key.code == sf::Keyboard::D) d = 0;
				if (event.key.code == sf::Keyboard::A) a = 0;

				if (event.key.code == sf::Keyboard::E) e = 0;
				if (event.key.code == sf::Keyboard::Q) q = 0;
			}
		}

		for (auto entity : *game.GetEntities()) {
			entity->Update(dt);
		}

		window.clear();

		for (auto entity : *game.GetEntities()) {
			auto drawables = entity->Draw();
			for (auto drawable : drawables) {
				window.draw(*drawable);
			}
		}

		window.display();
	}

	return 0;
}