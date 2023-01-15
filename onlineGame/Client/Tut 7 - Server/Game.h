
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "Player.h"
#include "Client.h"

class Game
{
public:
	Game();
	~Game();
	
	void run();

	std::string updatePlayersPos();
	std::string sendCheckedForPlayer();
	std::string CheckForCollisions();
	
private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void getNumberOfPlayer(std::string& string);

	sf::Vector2f getPosFromServer(std::string& opponentPos, bool smaller);
	int len(std::string string);
	void split(std::string string, char seperator, bool smaller);

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	Player player;
	Player Player2;
	Player Player3;

	Client myClient;

	//Arrays to hold players 2 & 3 position
	std::string opponentPosPlayer2[3];
	std::string opponentPosPlayer3[3];

	int numberOfPlayer = 0;

	std::string check;
};

#endif 
