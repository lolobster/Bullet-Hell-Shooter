#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& pos_start, const sf::Vector2f& pos_target, float angle)
	: GameObject(health)
{
	pos_bullet = pos_start;
	spr_bullet.setPosition(pos_bullet);
	spr_bullet.setRotation(angle);
	spr_bullet.setScale(sf::Vector2f(0.2f, 0.2f));

	float distance = sqrt((pos_target.x - pos_bullet.x)*(pos_target.x - pos_bullet.x) + (pos_target.y - pos_bullet.y)*(pos_target.y - pos_bullet.y));

	velocity.x = speed * (pos_target.x - pos_bullet.x) / distance;
	velocity.y = speed * (pos_target.y - pos_bullet.y) / distance;
}

Bullet::~Bullet()
{
}

Vector2f Bullet::getPos()
{
	return spr_bullet.getPosition();
}

void Bullet::update()
{
	pos_bullet += velocity;
	spr_bullet.setPosition(pos_bullet);

	bottom = collisionBox.getPosition().y + collisionBox.getSize().y;
	left = collisionBox.getPosition().x;
	right = collisionBox.getPosition().x + collisionBox.getSize().x;
	top = collisionBox.getPosition().y;
}

void Bullet::onCollision()
{
}
