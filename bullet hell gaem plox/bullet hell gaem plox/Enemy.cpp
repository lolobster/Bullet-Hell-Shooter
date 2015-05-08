#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& pos_start, const sf::Vector2f pos_waypoint,
	TextureManager& texMgr)
	: GameObject(health)
{
	position = pos_start;

	angle = atan2(pos_waypoint.y - position.y, pos_waypoint.x - position.x);
	angle = angle * (180 / PI);
	if (angle < 0)
	{
		angle = 360 - (-angle);
	}
	rotation = 90 + angle;

	spr_enemy.setTexture(texMgr.getRef("enemy"));
	spr_enemy.setPosition(position);
	spr_enemy.setRotation(rotation);
	spr_enemy.setScale(sf::Vector2f(1.0f, 1.0f));

	distance = sqrt((pos_waypoint.x - position.x)*(pos_waypoint.x - position.x) +
		(pos_waypoint.y - position.y)*(pos_waypoint.y - position.y));

	velocity = (pos_waypoint - position) / (distance * speed);
}

void Enemy::update()
{
	position += velocity;
	spr_enemy.setPosition(position);
}

void Enemy::onHit()
{
	
}

void Enemy::shoot()
{
}