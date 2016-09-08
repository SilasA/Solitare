#include "CardStack.h"
#include "Resources.h"
#include <algorithm>


CardStack::CardStack(std::vector<Card>& cardStack) :
	m_cardStack(cardStack)
{
	for (Card& card : m_cardStack)
	{
		Card::data dat = card.GetCardData();
		card.SetID(std::to_string(CARD_VALUES[(int)dat.cv] + CARD_SUITS[(int)dat.cv]));
	}
	// Uncover the last card in the stack
	m_cardStack.end()->SetCovered(false);
}

CardStack::CardStack()
{
}

CardStack::~CardStack()
{
	m_cardStack.clear();
}

Card& CardStack::Find(const Card::data& dat)
{
	return *std::find(m_cardStack.begin(), m_cardStack.end(), Card(dat));
}

bool CardStack::TransferCards(
	std::vector<Card>& first, std::vector<Card>& second, const Card::data& start)
{
	// Find starting point
	CardStack::CS_itr startItr = std::find(
		first.begin(), first.end(), Card(start));
	// Return if not found
	if (startItr == first.end()) return false;

	// Transfer
	second.insert(second.end(), startItr, first.end());
	first.erase(startItr, first.end());

	// Set last card in each to be uncovered
	first.end()->SetCovered(false);
	second.end()->SetCovered(false);
	return true;
}

bool CardStack::TransferCards(
	std::vector<Card>& first, std::vector<Card>& second,
	uint16_t startIdx, int16_t endIdx = -1)
{
	if (startIdx >= first.size()) return false;
	if (endIdx < 0) endIdx = startIdx;

	// Transfer
	second.insert(second.end(), first.begin() + startIdx, first.end());
	first.erase(first.begin() + startIdx, first.end());
	return true;
}
