#include "GameObject.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <list>

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

	bg_text.loadFromFile("starfield.png");
	bg_text.setSmooth(false);
	bg_text.setRepeated(true);
	bg_sprite.setTexture(bg_text);

	bgY = 0;
	bg_sprite.setTextureRect(IntRect(0, bgY, 1020, 1000));

	bullet_text.loadFromFile("bullet.png");
	bullet_text.setSmooth(true);// tasoittaa reunat
	bullet_sprite.setTexture(bullet_text);
	bullet_sprite.setScale(Vector2f(0.15f, 0.15f));
	bullet_sprite.setRotation(270);
	bullet_sprite.setPosition(900, 800);

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

void GameObject::shoot(const float elapsedTime)
{
	static const float FIRE_INTERVAL = 0.1f;

	fireTimer -= elapsedTime;
	Vector2f sijainti = positionPlayer;

	if (fireTimer <= 0.0f)
	{
		sijainti.y = -40.0f;
		spawnBullet(sijainti);
		sijainti.y = 40.0f;
		spawnBullet(sijainti);
		fireTimer = FIRE_INTERVAL;
	}
}

void GameObject::spawnBullet(const Vector2f& sijainti) // ei toimi vielä asjgaga
{
	GameObject bullet(bullet_text);
	const IntRect textureRectangle(0, 119, 50, 10);
	bullet.setTextureRectangle(textureRectangle);// tämä pitää muuttaa Playeriksi
	bullet.setPosition(sijainti);
	bullet_list.push_back(bullet);
}

void GameObject::render(RenderWindow* window)
{
	window->draw(bg_sprite);

	window->draw(pl_sprite);

	for (it = bullet_list.begin(); it != bullet_list.end(); it++)
		window->draw(bullet_sprite);
}

void GameObject::updateBullet(const float elapsedTime)
{
	Vector2f bulletPos;
	static const float BULLET_SPEED = 1.0f;


	for (it = bullet_list.begin(); it != bullet_list.end();)
	{


		bulletPos = positionPlayer;
		bulletPos.y += BULLET_SPEED * elapsedTime;
		it->setPosition(bulletPos);

		if (bulletPos.y > 1000 | bulletPos.y < 0)
		{
			it = bullet_list.erase(it);
		}
		else
		{
			++it;
		}
	}
}

GameObject::~GameObject()
{
}
