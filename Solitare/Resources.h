#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <map>

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
