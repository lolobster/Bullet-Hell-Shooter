#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& pos_start, const sf::Vector2f& pos_waypoint, float angle, TextureManager& texMan)
//Enemy::Enemy(sf::Vector2f& pos_start, const sf::Vector2f& pos_waypoint, float angle)
	: GameObject(health)
{
	spr_enemy.setTexture(texMan.getRef("enemy"));

	pos_enemy = pos_start;
	spr_enemy.setPosition(pos_enemy);
	spr_enemy.setRotation(angle);
	spr_enemy.setScale(sf::Vector2f(1.0f, 1.0f));

	float distance = sqrt((pos_waypoint.x - pos_enemy.x)*(pos_waypoint.x - pos_enemy.x) + (pos_waypoint.y - pos_enemy.y)*(pos_waypoint.y - pos_enemy.y));

	velocity.x = speed * (pos_waypoint.x - pos_enemy.x) / distance;
	velocity.y = speed * (pos_waypoint.y - pos_enemy.y) / distance;
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	//pos_enemy += velocity;
	//spr_enemy.setPosition(pos_enemy);

	bottom = collisionBox.getPosition().y + collisionBox.getSize().y;
	left = collisionBox.getPosition().x;
	right = collisionBox.getPosition().x + collisionBox.getSize().x;
	top = collisionBox.getPosition().y;
}

void Enemy::draw(sf::RenderWindow* window) // i have no idea what i'm doing D:
{
	window->draw(spr_enemy);
}

//bool Enemy::collision()
//{
//	if (right < e.left || left > e.right ||
//		top > e.bottom || bottom < e.top)
//	{
//		return false;
//	}
//	return true;
//}