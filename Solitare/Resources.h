#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <map>

#define CARD_HEIGHT 190
#define CARD_WIDTH 140

const char CARD_VALUES[13] { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
const char CARD_SUITS[4]   { 'C', 'H', 'D', 'S' };

const sf::IntRect BLUE_BG_RECT	{ 0, 1820, CARD_WIDTH, CARD_HEIGHT };
const sf::IntRect GREEN_BG_RECT { CARD_HEIGHT, 1820, CARD_WIDTH, CARD_HEIGHT };
const sf::IntRect RED_BG_RECT	{ CARD_HEIGHT * 2, 1820, CARD_WIDTH, CARD_HEIGHT };
const sf::IntRect TRANS_RECT	{ CARD_HEIGHT * 3, 1820, CARD_WIDTH, CARD_HEIGHT };

class Resources
{
private:

	static std::map<std::string, sf::Sprite> m_sprites;
	static std::map<std::string, sf::Sound> m_sounds;

public:
	static void Init();

	static bool SetGraphic(const std::string& key, const sf::Sprite& sprite);
	static bool GetSound(const std::string& key, const sf::Sound& sound);

	static inline sf::Sprite* GetGraphic(const std::string& key) 
	{
		if (m_sprites.find(key) == m_sprites.end()) return nullptr;
		return &m_sprites[key]; 
	}
	static inline sf::Sound*  GetSound(const std::string& key)
	{
		if (m_sounds.find(key) == m_sounds.end()) return nullptr;
		return &m_sounds[key];
	}
};

#endif // RESOURCE_H
