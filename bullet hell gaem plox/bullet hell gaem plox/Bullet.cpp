#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
	: GameObject(health)
{
	//spr_bullet = objMan.getObject("bullet");
	//position = startingPos;
	//spr_bullet.setPosition(position);
	//spr_bullet.setRotation(angle);
	//spr_bullet.setScale(sf::Vector2f(0.1f, 0.1f));

	//float distance = sqrt((targetPos.x - position.x)*(targetPos.x - position.x) + (targetPos.y - position.y)*(targetPos.y - position.y));

	//velocity.x = speed * (targetPos.x - position.x) / distance;
	//velocity.y = speed * (targetPos.y - position.y) / distance;
}

Bullet::~Bullet()
{
}

void Bullet::loadTextures()
{
	bullet_text.loadFromFile("bullet.png");
	bullet_text.setSmooth(true);// tasoittaa reunat
	bullet_sprite.setTexture(bullet_text);
	bullet_sprite.setScale(Vector2f(0.1f, 0.23f));
	bullet_sprite.setRotation(45);
	//bullet_sprite.setPosition(positionPlayer);
	if (!bullet_text.loadFromFile("bullet.png"))
		std::cout << "noooooooooooooo";
}

void Bullet::draw(RenderWindow& window)
{
	window.draw(bullet_sprite); // ei saa oikeeta sijaintai eikä päivitä :((((( niin paljon leukoja
}

//void Bullet::updateBullet(Time elapsedTime)
//{
//
//	const float elapsed = elapsedTime.asMicroseconds();
//	Vector2f bulletPos;
//	Vector2f velocity;
//	static const float BULLET_SPEED = 1.0f;
//
//	velocity.y += BULLET_SPEED * elapsed;
//
//	bulletPos.y += velocity.y;
//	bullet_sprite.move(bulletPos*elapsed);
//
//	//if (bulletPos.y > 1000 | bulletPos.y < 0)
//	//{
//	//	it = bullet_vec.erase(it);
//	//}
//	//else
//	//{
//	//	++it;
//	//}
//
//}


//
//void Bullet::updateBullet(const Time& elapsedTime)
//{
//	const float elapsed = elapsedTime.asMicroseconds();
//
//	Vector2f bulletPos;
//	static const float BULLET_SPEED = 1.0f;
//
//
//	for (it = bullet_vec.begin(); it != bullet_vec.end();)
//	{
//
//
//		bulletPos = positionPlayer;
//		bulletPos.y += BULLET_SPEED * elapsed;
//		it->setPosition(bulletPos);
//
//		if (bulletPos.y > 1000 | bulletPos.y < 0)
//		{
//			it = bullet_vec.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//}

//void Bullet::onHit(Bullet *bullet)
//{
//	delete bullet;
//}
