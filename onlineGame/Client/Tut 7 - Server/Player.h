#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include <sstream>

class Player
{
public:

	void init(std::string stringID);
	void render(sf::RenderWindow& win);
	

	void Movement(sf::Event t_event);
	
	void checkCollision(sf::CircleShape opponent);

	void setPlayerID(int ID);
	void setPosition(sf::Vector2f newPos);
	void setPlayerColor();

	sf::CircleShape getPlayer();

	bool isIDSet();

	int convertStringToID(std::string stringID);
	int getPlayerID();

	std::string getPlayerPosition();
	std::string getChecked();
	std::string CheckForCollision();

private:

	sf::Color color;

	sf::CircleShape m_circle;

	int playerID = -1;

	bool isColliding = false;
	bool IDSet = false;

};


