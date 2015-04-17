#include "TextureManager.h"


void TextureManager::loadTexture(const std::string& name, const std::string &filename)
{
	sf::Texture tex;
	tex.loadFromFile(filename);

	if (name != "background_game" && name != "background_menu")
	{
		tex.setSmooth(true);
	}
	else
	{
		tex.setSmooth(false);
	}

	this->textures[name] = tex;
}

sf::Texture& TextureManager::getRef(const std::string& texture)
{
	return this->textures.at(texture);
}