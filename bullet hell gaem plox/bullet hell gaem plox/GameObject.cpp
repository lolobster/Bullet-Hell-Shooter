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
	return spr_player.getPosition() + _origin;
}

void GameObject::setPosition(const Vector2f& value)  // asettaa uuden positionin
{
	spr_player.setPosition(value - _origin);
}

void GameObject::setTextureRectangle(const IntRect& value)  // jotain bullettien spawnaamiselle
{
	spr_bullet.setTextureRect(value);
	_origin.x = 0.5f*value.width;
	_origin.y = 0.5f*value.height;
}

void GameObject::textureManager(float deltaTime)
{
	tex_player.loadFromFile("textures/player.png");
	tex_player.setSmooth(true);// tasoittaa reunat
	spr_player.setTexture(tex_player);
	//spr_player.setPosition(950, 800);

	tex_background.loadFromFile("textures/background_game.png");
	tex_background.setSmooth(false);
	tex_background.setRepeated(true);
	spr_background.setTexture(tex_background);

	bgY = 0;
	spr_background.setTextureRect(IntRect(0, bgY, 1020, 1000));

	tex_bullet.loadFromFile("textures/bullet.png");
	tex_bullet.setSmooth(true);// tasoittaa reunat
	spr_bullet.setTexture(tex_bullet);
	spr_bullet.setScale(Vector2f(0.15f, 0.15f));
	spr_bullet.setRotation(270);
	spr_bullet.setPosition(900, 800);

	//tex_enemy.loadFromFile("textures/enemy.png");
	//tex_enemy.setSmooth(true);
	//spr_enemy.setTexture(tex_enemy);
	//spr_enemy.setPosition(950, 800);
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

	spr_background.setTextureRect(IntRect(0, bgY, 1900, 1000));
}

void GameObject::render(RenderWindow* window)  // renderöinti sprölölö
{
	window->draw(spr_background);
	window->draw(spr_player);
}

GameObject::~GameObject()
{
}
