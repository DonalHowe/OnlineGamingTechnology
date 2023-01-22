#include "Player.h"

void Player::init(std::string stringID)
{
	if (IDSet == false)
	{
		setPlayerID(convertStringToID(stringID));
		m_circle.setRadius(10u);
		m_circle.setPosition(100, 100);
	}
}

void Player::render(sf::RenderWindow& win)
{
	win.draw(m_circle);
}


void Player::Movement(sf::Event t_event)
{
	if (sf::Keyboard::W==t_event.key.code)
	{
		m_circle.move(0, -10);
	}
	if (sf::Keyboard::S==t_event.key.code)
	{
		m_circle.move(0, 10);
	}
	if (sf::Keyboard::A==t_event.key.code)
	{
		m_circle.move(-10, 0);
	}
	if (sf::Keyboard::D==t_event.key.code)
	{
		m_circle.move(10, 0);
	}

	

}


void Player::checkCollision(sf::CircleShape opponent)
{
	if (m_circle.getGlobalBounds().intersects(opponent.getGlobalBounds()))
	{
		m_circle.setFillColor(sf::Color::Yellow);
		isColliding = true;
	}

	else
	{
		m_circle.setFillColor(color);
		isColliding = false;
	}
}

void Player::update()
{
	if (m_circle.getPosition().x < 0)
	{
		m_circle.setPosition(ScreenSize::M_WIDTH, m_circle.getPosition().y);
	}
	if (m_circle.getPosition().x > ScreenSize::M_WIDTH)
	{
		m_circle.setPosition(0, m_circle.getPosition().y);
	}

	if (m_circle.getPosition().y < 0)
	{
		m_circle.setPosition(m_circle.getPosition().x, ScreenSize::M_HEIGHT);
	}

	if (m_circle.getPosition().y > ScreenSize::M_HEIGHT)
	{
		m_circle.setPosition(m_circle.getPosition().x, 0);
	}
}


sf::CircleShape Player::getPlayer()
{
	return m_circle;
}


std::string Player::getPlayerPosition()
{
	return std::to_string(getPlayerID()) + "," + std::to_string(m_circle.getPosition().x) + "," + std::to_string(m_circle.getPosition().y);
}


std::string Player::CheckForCollision()
{
	return std::to_string(isColliding); 
}

void Player::setPosition(sf::Vector2f newPos)
{
	m_circle.setPosition(newPos);
}

void Player::setPlayerColor()
{
	if (playerID == 0)
	{
		color = sf::Color::Blue;
	}
	else if (playerID == 1)
	{
		color = sf::Color::Green;
	}
	else if(playerID==2)
	{
		color = sf::Color::Cyan;
	}

	m_circle.setFillColor(color);
}

void Player::setPlayerID(int ID)
{
	playerID = ID;
	setPlayerColor();
	IDSet = true;
}

//Returns the players ID 
int Player::getPlayerID()
{
	return playerID;
}

//Method to change parameters in a string to an ID
int Player::convertStringToID(std::string stringID)
{
	std::istringstream stream(stringID);
	int result;
	stream >> result;
	return result;
}

bool Player::isIDSet()
{
	return IDSet;
}

std::string Player::getChecked()
{
	return std::to_string(10);
}


