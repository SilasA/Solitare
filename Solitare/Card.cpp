#include "Card.h"

Card::Card(sf::Sprite* sprite, 
	sf::Sound* sound, 
	CardValue value, 
	CardSuit suit, 
	bool uncovered = false) :
	m_graphic(sprite), m_sound(sound), m_cardval(value), m_cardsuit(suit),
	m_isBlack(suit == CardSuit::Clubs || suit == CardSuit::Spades)
{
}

Card::Card(const Card::data& dat) :
	m_cardval(dat.cv), m_cardsuit(dat.cs), m_isBlack(dat.isBlack)
{
}


Card::~Card()
{
}


bool Card::CompareCard(Card& first, Card& second)
{
	return first.GetValue() == second.GetValue() ?
		first.GetSuit() >= second.GetSuit() : first.GetValue() >= second.GetValue();
}
