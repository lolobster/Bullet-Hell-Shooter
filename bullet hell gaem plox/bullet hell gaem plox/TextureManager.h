#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>

class TextureManager
{
public:
	TextureManager(){}
	~TextureManager(){}

	void loadTexture(const std::string& name, const std::string &filename);
	sf::Texture& getRef(const std::string& texture);

private:
	std::map < std::string, sf::Texture> textures;

};
#endif