#include "Resources.h"

std::map<std::string, sf::Sprite> Resources::m_sprites;
std::map<std::string, sf::Sound> Resources::m_sounds;

void Resources::Init()
{
	// All cards
	int x{ 0 }, y{ 0 };
	sf::Texture tex;
	if (!tex.loadFromFile("Assets\\card_spritesheet.png"));
		// unable to load texture
	for (char suit : CARD_SUITS)
	{
		x = 0;
		for (char c : CARD_VALUES)
		{
			SetGraphic(std::to_string(c + suit), 
				sf::Sprite(tex, sf::IntRect(x, y, CARD_WIDTH, CARD_HEIGHT)));
			x += 140;
		}
		y += 190;
	}
	
	// Card back texture/sprite
	sf::Texture texCardBack;
	if (!texCardBack.loadFromFile("Assets\\cardBack_green.png"));
		// unable to load texture
	SetGraphic("cback", sf::Sprite(texCardBack, 
		sf::IntRect(0, 0, CARD_WIDTH, CARD_HEIGHT)));

	// Background
	sf::Texture bg;
	if (!bg.loadFromFile("Assets\\bg.png"));
		// unable to load texture
	SetGraphic("bg", sf::Sprite(bg));
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
