#include "CardStack.h"
#include <algorithm>


CardStack::CardStack(std::vector<Card>& cardStack) :
	m_cardStack(cardStack)
{
}

CardStack::~CardStack()
{
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
	return true;
}

bool CardStack::TransferCards(
	std::vector<Card>& first, std::vector<Card>& second, uint16_t startIdx)
{
	if (startIdx >= first.size()) return false;

	// Transfer
	second.insert(second.end(), first.begin() + startIdx, first.end());
	first.erase(first.begin() + startIdx, first.end());
	return true;
}
