#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Card Typing
enum class CardValue {
	Ace = 1,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
};
enum class CardSuit {
	Clubs,
	Diamonds,
	Hearts,
	Spades
};


//
class Card
{
private:
	//NOTE: Don't ever use delete
	sf::Sprite* m_graphic;
	sf::Sound* m_sound; 

	CardValue m_cardval;
	CardSuit  m_cardsuit;
	bool	  m_isBlack;
	bool	  m_uncovered;

public:
	// Type for data
	struct data
	{
		CardValue cv;
		CardSuit  cs;
		bool	  isBlack;

		data(CardValue val, CardSuit suit, bool black) :
			cv(val), cs(suit), isBlack(black) {}

		inline bool operator==(const data& left)
		{
			return cv == left.cv && cs == left.cs && isBlack == left.isBlack;
		}
	};

	Card(sf::Sprite* sprite, 
		sf::Sound* sound, 
		CardValue value, 
		CardSuit suit,
		bool uncovered = false);
	Card(const Card::data& dat);
	~Card();

	inline bool IsBlack() { return m_isBlack; }
	inline CardValue GetValue() { return m_cardval; }
	inline CardSuit GetSuit() { return m_cardsuit; }

	inline data GetCardData() const { return data(m_cardval, m_cardsuit, m_isBlack); }

	// Static Members
	static bool CompareCard(Card& first, Card& second);

	// Operators
	inline bool operator==(const Card& left)
	{
		return GetCardData() == left.GetCardData();
	}
};

#endif // CARD_H
