#ifndef GAME_H
#define GAME_H

#include "CardStack.h"

typedef std::pair<CardStack, CardStack> Hand_Waste;

#define TABLEAU_SIZE 7

class Game
{
private:
	std::vector<Card> m_fulldeck;

	bool m_completed;

	CardStack m_tableau[7];
	CardStack m_foundation[4];
	Hand_Waste m_handwaste;

	// Generates a list of cards of the given size based on cards in m_fulldeck
	//NOTE: If "size" exceeds "m_fulldeck.size()", this will not work. Use generate_fulldeck()
	std::vector<Card> generate_cardstack(uint16_t size);

public:
	Game();
	~Game();

	void HandleInput(sf::Event& event);
	void Draw(sf::RenderWindow& window);
	void Update(sf::Event& event);
};


#endif // GAME_H
