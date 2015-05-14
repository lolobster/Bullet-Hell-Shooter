#include "Bullet.h"
#include "Player.h"
#include "TextureManager.h"
#include <iostream>

Bullet::Bullet()
	: GameObject(health)
{

}

Bullet::~Bullet()
{
}

Bullet::Bullet(Vector2f pos_origin, Vector2f pos_target)
{
	bullet_text.loadFromFile("bullet.png");
	bullet_sprite.setTexture(bullet_text);
	bullet_sprite.setScale(Vector2f(0.15f, 0.1f));
	bullet_sprite.setRotation(270);

	position = pos_origin;

	angle = atan2(pos_target.y - position.y, pos_target.x - position.x);
	angle = angle * (180 / M_PI);
	if (angle < 0)
	{
		angle = 360 - (-angle);
	}

	bullet_sprite.setPosition(position);
	bullet_sprite.setRotation(angle);
	bullet_sprite.setScale(Vector2f(0.15f, 0.07f));

	distance = sqrt((pos_target.x - position.x)*(pos_target.x - position.x) +
		(pos_target.y - position.y)*(pos_target.y - position.y));

	velocity = (pos_target - position) / (distance * speed);
}

void Bullet::draw(RenderWindow& window)
{

	window.draw(bullet_sprite); 
}

void Bullet::updateBullet()
{
	position += velocity;
	bullet_sprite.setPosition(position);
}
