#include "SoundManager.h"

void SoundManager::loadTexture(const std::string& name, const std::string &filename)
{
	sf::SoundBuffer sfx;
	sfx.loadFromFile(filename);

	sounds[name] = sfx;
}

sf::SoundBuffer& SoundManager::getRef(const std::string& sfx)
{
	return sounds.at(sfx);
}