#include "Game.h"
#include <ctime>

std::vector<Card> Game::generate_cardstack(uint16_t size)
{
	std::vector<Card> genStack;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		CardStack::TransferCards(m_fulldeck, genStack, rand() % m_fulldeck.size());
	}
	return genStack;
}

Game::Game() :
	m_fulldeck(generate_full_deck())
{
	// Generate tableau
	for (int i = TABLEAU_SIZE - 1; i >= 0; i--)
		m_tableau[i] = generate_cardstack(i + 1);

	// Put remaining cards into the hand
	m_handwaste.first = generate_cardstack(m_fulldeck.size());
	m_fulldeck.clear();
}

Game::~Game()
{
}

void Game::HandleInput(sf::Event& event)
{

}

void Game::Draw(sf::RenderWindow& window)
{
}

void Game::Update(sf::Event& event)
{
}
