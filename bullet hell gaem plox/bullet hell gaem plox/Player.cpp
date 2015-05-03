#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "GameObject.h"

using namespace sf;

Player::Player(Vector2f pos)
	: GameObject(health)
{

	positionPlayer = pos;


}


Player::~Player()
{
}

void Player::updatePlayer(const Time& elapsedTime)
{
	const float elapsed = elapsedTime.asMicroseconds();
	//playerController(elapsed);
	//if (Mouse::isButtonPressed())
	updateBullet(elapsedTime);
	playerController(elapsed);
}

void Player::onHit()
{
	health -= 1;

	if (health == 0)
	{
		deaths = +1;
	}
}


void Player::playerController(const float elapsedTime)
{
	Mouse mouse;
	Bullet bullet;


	if (Mouse::isButtonPressed(btn_shoot))
	{


		shoot(elapsedTime); //begin shoot action
	}
	if (Mouse::isButtonPressed(btn_use))
	{
		// add functions
	}

	// LIIKKEET //

	if (Keyboard::isKeyPressed(kb_left))
	{
		// liikettä vasempaan
		positionPlayer.x -= 0.24 * elapsedTime;
	}
	if (Keyboard::isKeyPressed(kb_right))
	{
		// liikettä oikeaan
		positionPlayer.x += 0.24 * elapsedTime;
	}
	if (Keyboard::isKeyPressed(kb_forward))
	{
		// liikettä ylöspäin
		positionPlayer.y -= 0.15 * elapsedTime;
	}
	if (Keyboard::isKeyPressed(kb_reverse))
	{
		// liikettä alaspäin
		positionPlayer.y += 0.15 * elapsedTime;
	}

	pl_sprite.setPosition(positionPlayer);
}

void Player::shoot(const float elapsedTime)
{
	static const float FIRE_INTERVAL = 0.1f;

	fireTimer -= elapsedTime;
	Vector2f sijainti = positionPlayer;

	if (fireTimer <= 0.0f)
	{
		sijainti.y = -20.0f;
		Bullet *shot=new Bullet(sijainti);
		shot->loadTextures();
		bullet_vec.push_back(shot);
		fireTimer = FIRE_INTERVAL;
	}
}

void Player::draw(RenderWindow& window)
{
	for (it = bullet_vec.begin(); it != bullet_vec.end(); it++)
	{
		(*it)->getSprite();
		(*it)->draw(window);
	}
	//window.draw(bullet_sprite);
}

void Player::updateBullet(const Time& elapsedTime)
{
//const float elapsed = elapsedTime.asMicroseconds();
//Vector2f bulletPos;
//Vector2f velocity;
//static const float BULLET_SPEED = 1.0f;
//
//velocity.y += BULLET_SPEED * elapsed;
//
//bulletPos.y += velocity.y;
//bullet_sprite.move(bulletPos*elapsed);

	const float elapsed = elapsedTime.asMicroseconds();

	Vector2f bulletPos;
	Vector2f velocity;
	static const float BULLET_SPEED = 1.0f;


	for (it = bullet_vec.begin(); it != bullet_vec.end();)
	{


		bulletPos = positionPlayer;
		velocity.y += BULLET_SPEED * elapsed;
		/*it = bulletPos;*/

		velocity.y += BULLET_SPEED * elapsed;
		
		bulletPos.y += velocity.y;
		/*bulletPos += velocity;
		(*it)->bulletPos;*/

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