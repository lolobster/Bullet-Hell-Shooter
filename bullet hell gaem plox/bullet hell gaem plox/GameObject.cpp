#include "GameObject.h"
#include <string>
#include <iostream>

using namespace sf;

GameObject::GameObject(int h)
{
	health = h;
	textureManager();
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

void GameObject::textureManager()
{

	pl_text.loadFromFile("Bat.png");
	pl_text.setSmooth(true);// tasoittaa reunat
	pl_sprite.setTexture(pl_text);
	pl_sprite.setPosition(550, 1000);
	// MITEN VITUSSA PELAAJA SAA TEXTURET???!?!???!??


	bg_text.loadFromFile("bg.png");
	bg_text.setSmooth(false);
	bg_sprite.setTexture(bg_text);
	// LAITA TAUSTA RULLAAMAAN

	// BULLETILLE JA ENEMYLLE TEXTUUUUUUUUUURITTTTT
	ene_text.loadFromFile("base_enemy.png");
	ene_text.setSmooth(true);
	ene_sprite.setTexture(ene_text);
}

void GameObject::render(sf::RenderWindow* window)  // renderöinti
{

	window->clear(sf::Color::Black); // täyttää koko ikkunan mustalla värillä


	window->draw(bg_sprite);
	window->draw(pl_sprite);
	window->draw(ene_sprite);
}

GameObject::~GameObject()
{
}
