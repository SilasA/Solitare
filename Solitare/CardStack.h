#ifndef CARD_STACK_H
#define CARD_STACK_H

#include "Card.h"
#include <vector>

class CardStack
{
private:
	std::vector<Card> m_cardStack;

public:
	typedef std::vector<Card>::iterator CS_itr;

	CardStack(std::vector<Card>& cardStack);
	~CardStack();

	static bool TransferCards(
		std::vector<Card>& first, 
		std::vector<Card>& second, 
		const Card::data& start);
	static bool TransferCards(
		std::vector<Card>& first,
		std::vector<Card>& second,
		uint16_t startIdx);
};

// Returns a CardStack representing a Full 52 deck of cards
inline std::vector<Card> generate_full_deck()
{
	std::vector<Card> fulldeck;
	for (int suit = 0; suit < 4; suit++)
		for (int i = 0; i < 13; i++)
			fulldeck.push_back(Card(Card::data(
			(CardValue)i, (CardSuit)suit, suit == 0 || suit == 3)));
	return fulldeck;
}

#endif // CARD_STACK_H