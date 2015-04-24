#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& pos_start, const sf::Vector2f pos_waypoint,
	float angle, TextureManager& texMgr)
	: GameObject(health)
{
	position = pos_start;
	spr_enemy.setTexture(texMgr.getRef("enemy"));
	spr_enemy.setPosition(position);
	spr_enemy.setRotation(angle);
	spr_enemy.setScale(sf::Vector2f(1.0f, 1.0f));

}

void Enemy::update()
{
	position += movement;
	spr_enemy.setPosition(position);
}

void Enemy::shoot()
{

}