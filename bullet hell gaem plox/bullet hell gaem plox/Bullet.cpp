#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& pos_origin, const sf::Vector2f& pos_target, float angle)
	: GameObject()
{
	position = pos_origin;
	//spr_bullet.setTexture(texMgr.getRef("bullet"));
	spr_bullet.setPosition(position);
	spr_bullet.setRotation(angle);
	spr_bullet.setScale(0.3f, 0.3f);
}

void Bullet::update()
{
	position += velocity;
	spr_bullet.setPosition(position);
}