#include "Resources.h"


void Resources::Init()
{
	sf::Texture tex;
	if (!tex.loadFromFile());
		// unable to load texture
	SetGraphic("AC", sf::Sprite(tex, sf::IntRect())
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
