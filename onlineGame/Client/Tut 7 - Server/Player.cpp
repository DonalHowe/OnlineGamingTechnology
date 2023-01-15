#include "Player.h"

void Player::init(std::string stringID)
{
	setPlayerID(convertStringToID(stringID));

	setPlayerColor();


	m_player.setRadius(10u);
	m_player.setPosition(100, 100);

}

void Player::render(sf::RenderWindow& win)
{
	win.draw(m_player);
}

void Player::update()
{
	if (playerID == 0)
	{
		playerMovement();
	}

	//this is for testing with another client started on local PC
	else if (playerID == 1)
	{
		player2Movement();
	}
}

void Player::playerMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player.move(0, -10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.move(0, 10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player.move(-10, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player.move(10, 0);
	}
}

void Player::player2Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_player.move(0, -10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_player.move(0, 10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_player.move(-10, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player.move(10, 0);
	}
}

//This Method is checking for collision between players
void Player::checkCollision(sf::CircleShape opponent)
{
	if (m_player.getGlobalBounds().intersects(opponent.getGlobalBounds()))
	{
		m_player.setFillColor(sf::Color::Yellow);
		std::cout << "Player: " << getPlayerID() << "is colliding" << std::endl;
		isColliding = true;
	}

	else
	{
		m_player.setFillColor(color);
		isColliding = false;
	}
}

//This Get Method is returning the players body or rectangle shape.
sf::CircleShape Player::getPlayer()
{
	return m_player;
}

//This method returns a string of the current players X and Y positions
std::string Player::getPlayerPosition()
{
	return std::to_string(getPlayerID()) + "," + std::to_string(m_player.getPosition().x) + "," + std::to_string(m_player.getPosition().y);
}

//String method to return if collision happened or not
std::string Player::CheckForCollision()
{
	return std::to_string(isColliding); // 1 is colliding , 0 is not 
}

//Set method to set the players position
void Player::setPosition(sf::Vector2f newPos)
{
	m_player.setPosition(newPos);
}

//Method to set the players colors as they join
void Player::setPlayerColor()
{
	switch (playerID)
	{
	case 1:
		color = sf::Color::Blue;
		break;
	case 2:
		color = sf::Color::Magenta;
		break;
	default:
		color = sf::Color::Red;
		break;
	}

	m_player.setFillColor(color);
}

//Method to set the players ID and to set their color
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


