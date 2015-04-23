#include "TextureManager.h"
#include "GameObject.h"

using namespace sf;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	delete pl_text;
	delete bg_text;
	delete ene_text;
	delete bullet_text;
	delete pl_sprite;
	delete bg_sprite;
	delete ene_sprite;
	delete bullet_sprite;
}

void TextureManager::loadTextures()
{
	pl_text->loadFromFile("textures/Player.png");
	pl_text->setSmooth(true);// tasoittaa reunat
	pl_sprite->setTexture(*pl_text);

	bg_text->loadFromFile("textures/starfield.png");
	bg_text->setSmooth(false);
	bg_text->setRepeated(true);
	bg_sprite->setTexture(*bg_text);

	float bgY = 0;
	bg_sprite->setTextureRect(IntRect(0, bgY, 1020, 1000));

	ene_text->loadFromFile("textures/base_enemy.png");
	ene_text->setSmooth(true);
	ene_sprite->setTexture(*ene_text);
	ene_sprite->setPosition(600, 500);
}