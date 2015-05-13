#include "Enemy.h"

Enemy::Enemy(sf::Vector2f& pos_start, sf::Vector2f pos_waypoint,
	TextureManager& texMgr)
	: GameObject(health)
{
	position = pos_start;
	pos_direction = pos_waypoint;

	angle = atan2(pos_waypoint.y - position.y, pos_waypoint.x - position.x);
	angle = angle * (180 / M_PI);
	if (angle < 0)
	{
		angle = 360 - (-angle);
	}
	angle -= 90;

	spr_enemy.setTexture(texMgr.getRef("enemy"));
	spr_enemy.setPosition(position);
	spr_enemy.setRotation(angle);
	spr_enemy.setScale(sf::Vector2f(0.8f, 0.8f));

	distance = sqrt((pos_waypoint.x - position.x)*(pos_waypoint.x - position.x) +
		(pos_waypoint.y - position.y)*(pos_waypoint.y - position.y));

	velocity = (pos_waypoint - position) / (distance * speed);
}

void Enemy::draw(RenderWindow* window)
{
	window->draw(spr_enemy);
}

void Enemy::update(Time& elapsed)
{
	position += velocity;
	spr_enemy.setPosition(position);
	//shoot(elapsed.asMilliseconds());
}

//void Enemy::shoot(const float elapsedTime)
//{
//	static const float FIRE_INTERVAL = 250.0f;
//
//	fireTimer -= elapsedTime;
//	position.x += 30.0f;
//	//sijainti.y = -20.0f;
//	if (fireTimer <= 0.0f)
//	{
//		Bullet *shot = new Bullet(position, pos_direction);
//
//		bullet_vec.push_back(shot);
//		fireTimer = FIRE_INTERVAL;
//	}
//}
//
//void Enemy::updateBullet(const Time& elapsedTime)
//{
//
//	const float elapsed = elapsedTime.asMicroseconds();
//
//	Vector2f bulletPos;
//
//	for (it = bullet_vec.begin(); it != bullet_vec.end();)
//	{
//		(*it)->updateBullet();
//
//		bulletPos = (*it)->getSprite().getPosition();
//
//		if (bulletPos.y > 1000 || bulletPos.y < 0)
//		{
//			it = bullet_vec.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//}