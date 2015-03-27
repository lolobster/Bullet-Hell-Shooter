#include "GameObject.h"
#include <string>
#include <iostream>

using namespace sf;

GameObject::GameObject(int h)
{
	health = h;
	textureManager(0);
}

void GameObject::update(sf::RenderWindow &window, float elapsedTime)
{
	// käytä time::elapsed
}

Vector2f GameObject::position() const
{
	return pl_sprite.getPosition() + _origin;
}

void GameObject::setPosition(const Vector2f& value)  // asettaa uuden positionin
{
	pl_sprite.setPosition(value - _origin);
}

void GameObject::textureManager(float deltaTime)
{

	pl_text.loadFromFile("Player.png");
	pl_text.setSmooth(true);// tasoittaa reunat
	pl_sprite.setTexture(pl_text);
	pl_sprite.setPosition(950, 900);

	bg_text.loadFromFile("bg.png");
	bg_text.setSmooth(false);
	bg_text.setRepeated(true);
	bg_sprite.setTexture(bg_text);
	////// liikkuva tausta
	//bg_sprite.setPosition(0, 0);
	bgY = 0;
	bg_sprite.setTextureRect(IntRect(0, bgY, 1920, 1200));


	// BULLETILLE TEXTUUUUUUUUUURITTTTT
	ene_text.loadFromFile("base_enemy.png");
	ene_text.setSmooth(true);
	ene_sprite.setTexture(ene_text);
}
void GameObject::updateBackGround(float deltaTime)
{

	if (bgY < 1200)
	{
		bgY -= 0.05 * deltaTime;
	}
	else
	{
		bgY = 0;
	}

	bg_sprite.setTextureRect(IntRect(0, bgY, 1920, 1200));
}

void GameObject::render(sf::RenderWindow* window)  // renderöinti sprölölö
{

	window->clear(sf::Color::Black); // täyttää koko ikkunan mustalla värillä


	window->draw(bg_sprite);
	window->draw(pl_sprite);
	window->draw(ene_sprite);
}

GameObject::~GameObject()
{
}
