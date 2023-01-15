#include "Game.h"
#include <iostream>


Game::Game() :
	m_window{ sf::VideoMode{ ScreenSize::M_WIDTH, ScreenSize::M_HEIGHT, 32U }, "Networked Tag Game " },
	m_exitGame{ false }, myClient("127.0.0.1", 623) //when true game will exit
{
	if (!myClient.Connect()) //If client fails to connect...
	{
		std::cout << "Failed to connect to server..." << std::endl;
		system("pause");
	}
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

std::string Game::updatePlayersPos()
{
	return player.getPlayerPosition();
}

std::string Game::CheckForCollisions()
{
	return player.CheckForCollision();
}

std::string Game::sendCheckedForPlayer()
{
	return player.getChecked();
}


void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}



void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}


void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	if (!player.isIDSet())
	{
		player.init(myClient.getID_Message());
	}
	player.update();

	player.checkCollision(Player2.getPlayer());

	if (numberOfPlayer == 3)
	{
		Player2.setPosition(getPosFromServer(myClient.getPositionMessage(), true));
		Player3.setPosition(getPosFromServer(myClient.getPositionMessage(), false));
	}
	else
	{
		Player2.setPosition(getPosFromServer(myClient.getPositionMessage(), true));
	}

	if (!myClient.SendPosition(updatePlayersPos()))
	{
		std::cout << "Failed to send position" << std::endl;
	}

	if (!myClient.SendNum(sendCheckedForPlayer()))
	{
		std::cout << "Failed to receive number of player" << std::endl;
	}
	else
	{
		getNumberOfPlayer(myClient.getPlayerNum_Message());
	}


	if (!Player2.isIDSet() && !opponentPosPlayer2[0].empty())
	{
		Player2.init(opponentPosPlayer2[0]);
		std::cout << Player2.getPlayerID() << std::endl;
	}

	if (numberOfPlayer == 3 && !Player3.isIDSet() && !opponentPosPlayer3[0].empty())
	{
		Player3.init(opponentPosPlayer3[0]);
		std::cout << Player3.getPlayerID() << std::endl;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	Player2.render(m_window);
	Player3.render(m_window);
	player.render(m_window);
	m_window.display();
}

void Game::getNumberOfPlayer(std::string& string)
{
	if (!string.empty())
	{
		if (string == "1" || string == "2" || string == "3")
		{
			//std::cout << string << std::endl;
			numberOfPlayer = std::stoi(string);
		}
	}
}

sf::Vector2f Game::getPosFromServer(std::string& opponentPos, bool smaller)
{
	if (smaller)
	{
		if (!opponentPos.empty())
		{
			char seperator = ',';
			split(opponentPos, seperator, smaller);
			return sf::Vector2f(std::stof(opponentPosPlayer2[1]), std::stof(opponentPosPlayer2[2]));
		}
	}
	else if (!smaller && numberOfPlayer == 3)
	{
		if (!opponentPos.empty())
		{
			char seperator = ',';
			split(opponentPos, seperator, smaller);
			return sf::Vector2f(std::stof(opponentPosPlayer3[1]), std::stof(opponentPosPlayer3[2]));
		}
	}

	return sf::Vector2f(0, 0);
}

int Game::len(std::string string)
{
	int length = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

void Game::split(std::string string, char seperator, bool smaller)
{
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;

	while (i <= len(string))
	{
		if (smaller)
		{
			if (string[i] == seperator || i == len(string))
			{
				endIndex = i;
				std::string subStr = "";
				subStr.append(string, startIndex, endIndex - startIndex);
				opponentPosPlayer2[currIndex] = subStr;
				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
		else if (!smaller && numberOfPlayer == 3)
		{
			if (string[i] == seperator || i == len(string))
			{
				endIndex = i;
				std::string subStr = "";
				subStr.append(string, startIndex, endIndex - startIndex);
				opponentPosPlayer3[currIndex] = subStr;
				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
	}

	
}
