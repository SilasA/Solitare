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

	std::string m_id;

	CardValue m_cardval;
	CardSuit  m_cardsuit;
	bool	  m_isBlack;
	bool	  m_covered;

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
		bool covered = true);
	Card(const Card::data& dat);
	~Card();

	inline bool IsBlack() { return m_isBlack; }
	inline CardValue GetValue() { return m_cardval; }
	inline CardSuit GetSuit() { return m_cardsuit; }

	inline sf::Sprite* GetSprite() { return m_graphic; }
	inline sf::Sound* GetSound() { return m_sound; }

	inline std::string& GetID() { return m_id; }
	void SetID(std::string& id);

	void SetCovered(bool covered) { m_covered = covered; }
	bool IsCovered() { return m_covered; }

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
