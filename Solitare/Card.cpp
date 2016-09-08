#include "Card.h"
#include "Resources.h"

Card::Card(sf::Sprite* sprite, 
	sf::Sound* sound, 
	CardValue value, 
	CardSuit suit, 
	bool uncovered) :
	m_graphic(sprite), m_sound(sound), m_cardval(value), m_cardsuit(suit),
	m_isBlack(suit == CardSuit::Clubs || suit == CardSuit::Spades)
{
}

Card::Card(const Card::data& dat) :
	m_cardval(dat.cv), m_cardsuit(dat.cs), m_isBlack(dat.isBlack),
	m_sound(Resources::GetSound("card"))
{
	
}


Card::~Card()
{
}


void Card::SetID(std::string& id)
{
	m_id = id;
	m_graphic = Resources::GetGraphic(m_id);
}


bool Card::CompareCard(Card& first, Card& second)
{
	return first.GetValue() == second.GetValue() ?
		first.GetSuit() >= second.GetSuit() : first.GetValue() >= second.GetValue();
}
