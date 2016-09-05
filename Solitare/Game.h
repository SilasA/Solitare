#ifndef GAME_H
#define GAME_H

#include "CardStack.h"

typedef std::pair<CardStack, CardStack> Hand_Waste;

class Game
{
private:
	std::vector<Card> m_fulldeck;

	bool m_completed;

	CardStack m_tableau[7];
	CardStack m_foundation[4];
	Hand_Waste m_handwaste;

	std::vector<Card> generate_cardstack(uint16_t size);

public:
	Game();
	~Game();
};


#endif // GAME_H
