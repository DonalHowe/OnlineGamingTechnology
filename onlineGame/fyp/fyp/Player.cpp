#include "Player.h"

void Player::update(sf::Time t_deltatime)
{
	movement();
	boundsCheck();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_circle);
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_circle.move(-2, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_circle.move(2, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_circle.move(0, -2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_circle.move(0, 2);
	}
}

void Player::boundsCheck()
{
	if (m_circle.getPosition().x > ScreenSize::M_WIDTH)
	{
		m_circle.setPosition(0, m_circle.getPosition().y);
	}
	if (m_circle.getPosition().x <0)
	{
		m_circle.setPosition(ScreenSize::M_WIDTH-10, m_circle.getPosition().y);
	}
	if (m_circle.getPosition().y > ScreenSize::M_HEIGHT)
	{
		m_circle.setPosition(m_circle.getPosition().x, 0);
	}
	if (m_circle.getPosition().y < 0)
	{
		m_circle.setPosition(m_circle.getPosition().x, ScreenSize::M_HEIGHT-10);
	}
}

void Player::selectColour(sf::Color t_color)
{
	m_circle.setFillColor(t_color);
}

Player::Player()
{
	
	m_circle.setRadius(10);

}

Player::~Player()
{
}
