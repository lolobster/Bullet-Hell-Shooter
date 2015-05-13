#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <map>
#include <string>
#include <SFML/Audio/SoundBuffer.hpp>

class SoundManager
{
public:
	SoundManager(){}
	~SoundManager(){}

	void loadTexture(const std::string& name, const std::string &filename);
	sf::SoundBuffer& getRef(const std::string& sound);

private:
	std::map < std::string, sf::SoundBuffer> sounds;

};
#endif