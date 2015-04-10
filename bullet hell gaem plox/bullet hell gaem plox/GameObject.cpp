#include "GameObject.h"
#include "Player.h"
#include <string>
#include <iostream>

using namespace sf;

GameObject::GameObject(int h)
{
	health = h;
	//textureManager(0);
}

Vector2f GameObject::position() const
{
	return pl_sprite.getPosition() + _origin;
}

void GameObject::setPosition(const Vector2f& value)  // asettaa uuden positionin
{
	pl_sprite.setPosition(value - _origin);
}

void GameObject::setTextureRectangle(const IntRect& value)  // jotain bullettien spawnaamiselle
{
	bullet_sprite.setTextureRect(value);
	_origin.x = 0.5f*value.width;
	_origin.y = 0.5f*value.height;
}

void GameObject::textureManager(float deltaTime)
{

	pl_text.loadFromFile("Player.png");
	pl_text.setSmooth(true);// tasoittaa reunat
	pl_sprite.setTexture(pl_text);
	pl_sprite.setPosition(950, 800);

	bg_text.loadFromFile("bg.png");
	bg_text.setSmooth(false);
	bg_text.setRepeated(true);
	bg_sprite.setTexture(bg_text);

	bgY = 0;
	bg_sprite.setTextureRect(IntRect(0, bgY, 1020, 1000));

	bullet_text.loadFromFile("bullet.png");
	bullet_text.setSmooth(true);// tasoittaa reunat
	bullet_sprite.setTexture(bullet_text);
	bullet_sprite.setScale(Vector2f(0.15f, 0.15f));

	ene_text.loadFromFile("base_enemy.png");
	ene_text.setSmooth(true);
	ene_sprite.setTexture(ene_text);
}
void GameObject::updateBackGround(float deltaTime)
{

	if (bgY < 1000)
	{
		bgY -= 0.04 * deltaTime;
	}
	else
	{
		bgY = 0;
	}

	bg_sprite.setTextureRect(IntRect(0, bgY, 1900, 1000));
}

void GameObject::render(RenderWindow* window)  // renderöinti sprölölö
{
	
}

GameObject::~GameObject()
{
}
