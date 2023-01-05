#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Game.h"
#include "Server.h"


int main()
{

	Server MyServer(1111, false); //Create server on port 1111, false=do not loopback to localhost (others can connect)
	while (true)
	{
		MyServer.ListenForNewConnection(); //Accept new connection (if someones trying to connect)
	}
	Game game;
	game.run();

	return 1; 
}