#include "Game.h"
#include <ctime>

std::vector<Card> Game::generate_cardstack(uint16_t size)
{
	std::vector<Card> genStack;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		CardStack::TransferCards(m_fulldeck, genStack, rand() % 52);
	return genStack;
}

Game::Game() :
	m_fulldeck(generate_full_deck())
{
}

Game::~Game()
{
}
