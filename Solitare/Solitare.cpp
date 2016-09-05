// Solitare.cpp : Defines the entry point for the console application.
//
// --TEMPLATE FOR SFML PROJECT--

#include "Resources.h"

int main()
{
	Resources::Init();
	sf::RenderWindow window;

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

