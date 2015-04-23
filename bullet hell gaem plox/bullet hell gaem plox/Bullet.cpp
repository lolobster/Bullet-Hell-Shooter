#include "Bullet.h"
#include <iostream>

Bullet::Bullet(Sprite bullet_sprite)
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
	bullet_text.loadFromFile("textures/bullet.png");
	bullet_text.setSmooth(true);// tasoittaa reunat
	bullet_sprite.setTexture(bullet_text);
	bullet_sprite.setScale(Vector2f(0.15f, 0.2f));
	bullet_sprite.setRotation(270);
	//bullet_sprite.setPosition(900, 800);
	if (!bullet_text.loadFromFile("textures/bullet.png"))
		std::cout << "noooooooooooooo";
}



void Bullet::spawnBullet(const Vector2f& sijainti) // ei toimi vielä asjgaga
{
	//Bullet bullet(bullet_sprite);
	//const IntRect textureRectangle(0, 119, 50, 10);
	//bullet.setTextureRectangle(textureRectangle);// tämä pitää muuttaa Playeriksi
	bullet_sprite.setPosition(sijainti);
	bullet_vec.push_back(bullet_sprite);
}

void Bullet::updateBullet(const Time& elapsedTime)
{
	const float elapsed = elapsedTime.asMicroseconds();

	Vector2f bulletPos;
	static const float BULLET_SPEED = 1.0f;


	for (it = bullet_vec.begin(); it != bullet_vec.end();)
	{


		bulletPos = positionPlayer;
		bulletPos.y += BULLET_SPEED * elapsed;
		it->setPosition(bulletPos);

		if (bulletPos.y > 1000 | bulletPos.y < 0)
		{
			it = bullet_vec.erase(it);
		}
		else
		{
			++it;
		}
	}
}

//void Bullet::onHit(Bullet *bullet)
//{
//	delete bullet;
//}
