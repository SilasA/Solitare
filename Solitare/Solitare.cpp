// Solitare.cpp : Defines the entry point for the console application.
//
// --TEMPLATE FOR SFML PROJECT--

#include "Resources.h"
#include "Game.h"

int main()
{
	Resources::Init();
	sf::RenderWindow window;

	Game game;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}
	}
    return 0;
}

