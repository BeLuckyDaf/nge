#include "Circle.h"
#include "Game.h"

Circle::Circle(float x, float y, float radius)
{
    m_shape = new sf::CircleShape(radius);
	sf::Color fillColor(255, 0, 0);
    m_shape->setFillColor(fillColor);
    m_shape->setOrigin(m_shape->getLocalBounds().width / 2, m_shape->getLocalBounds().height / 2);
	this->m_x = x;
	this->m_y = y;

	m_texture = new sf::Texture();
	m_texture->loadFromFile("Assets/crosshair.png");
    m_sprite = new sf::Sprite(*m_texture);
    m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2, m_sprite->getLocalBounds().height / 2);
    m_sprite->setScale(2.f, 2.f);

}

void Circle::init()
{
}

void Circle::update(sf::Time &dt)
{
    // Follow the cursor
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*Game::instance()->getWindow());
    m_sprite->setPosition(mousePosition.x, mousePosition.y);
}

std::vector<sf::Drawable*> Circle::draw()
{
	std::vector<sf::Drawable*> result;
	result.push_back(m_sprite);

	return result;
}
