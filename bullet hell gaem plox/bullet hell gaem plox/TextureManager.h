#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

struct TextureManager
{
	TextureManager();
	~TextureManager();

	
	Texture* pl_text;
	
	Texture* bg_text;
	Sprite* ene_sprite;
	Texture* ene_text;
	Texture* bullet_text;
	Sprite* bullet_sprite;

	void loadTextures();
	TextureManager* textureManager;
};

#endif