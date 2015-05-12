#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"
#include <string>
#include <iostream>
#include <vector>

using namespace sf;

GameObject::GameObject(int h)
{
	health = h;
	

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
	//bullet_sprite.setTextureRect(value);
	_origin.x = 0.5f*value.width;
	_origin.y = 0.5f*value.height;
}

void GameObject::loadBackground()
{
	bg_text.loadFromFile("textures/starfield.png");
	bg_text.setSmooth(false);
	bg_text.setRepeated(true);
	bg_sprite.setTexture(bg_text);
	bgY = 0;
	bg_sprite.setTextureRect(IntRect(0, bgY, 1900, 1000));
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

void GameObject::render(RenderWindow* window)
{
	window->draw(bg_sprite);
	window->draw(pl_sprite);

}

GameObject::~GameObject()
{
}