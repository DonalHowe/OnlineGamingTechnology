#pragma once

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"

class Player
{

public:
	sf::CircleShape m_circle;
	
	void update(sf::Time t_deltatime);
	void render(sf::RenderWindow& t_window);
	void movement();
	void boundsCheck();
	void selectColour(sf::Color t_color);
	Player();
	~Player();

};

