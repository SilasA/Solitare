#include "Resources.h"

#define CARD_HEIGHT 190
#define CARD_WIDTH 140

void Resources::Init()
{
	int x{ 0 }, y{ 0 };
	sf::Texture tex;
	if (!tex.loadFromFile("Assets\\card_spritesheet.png"));
		// unable to load texture
	for (char suit : { 'C', 'H', 'D', 'S' })
	{
		x = 0;
		for (char c : 
			{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' })
		{
			SetGraphic(std::to_string(c + suit), 
				sf::Sprite(tex, sf::IntRect(x, y, CARD_WIDTH, CARD_HEIGHT)));
			x += 140;
		}
			y += 190;
	}
}

bool Resources::SetGraphic(const std::string& key, const sf::Sprite& sprite)
{
	if (m_sprites.find(key) == m_sprites.end()) return false;
	m_sprites[key] = sprite;
	return true;
}

bool Resources::GetSound(const std::string& key, const sf::Sound& sound)
{
	if (m_sounds.find(key) == m_sounds.end()) return false;
	m_sounds[key] = sound;
	return true;
}
