#include "Player.h"
#include "Menu.h"
#include "GameObject.h"

using namespace sf;

Player::Player()
	: GameObject(health)
{
	posX = pl_sprite.getPosition().x;
	posY = pl_sprite.getPosition().y;
}


Player::~Player()
{
}

void Player::onHit()
{
	health -= 1;

	if (health == 0)
	{
		deaths=+1;
	}
}


void Player::playerController(const float deltaTime)
{
			Mouse mouse;
			Vector2f playerPos(posX, posY);
			playerPos = _player.position();

			if (Mouse::isButtonPressed(btn_shoot))
			{
				//posX = mouse.getPosition().x; // mouse position on X axis is aquired
				//posY = mouse.getPosition().y; // mouse position on Y axis is aquired

				shoot(deltaTime); //begin shoot action
			}
			if (Mouse::isButtonPressed(btn_use))
			{
				// add functions
			}

			// LIIKKEET //

			if (Keyboard::isKeyPressed(kb_left))
			{
				// liikettä vasempaan
				posX -= 0.4 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_right))
			{
				// liikettä oikeaan
				posX += 0.4 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_forward))
			{
				// liikettä ylöspäin
				posY -= 0.4 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_reverse))
			{
				// liikettä alaspäin
				posY += 0.4 * deltaTime;
			}
	
			pl_sprite.setPosition(posX, posY);
}

void Player::shoot(const float deltaTime)
{
	static const float FIRE_INTERVAL = 0.1f;

	fireTimer -= deltaTime;
	Vector2f sijainti;

	if (fireTimer <= 0.2f)
	{
		sijainti.y = -40.0f;
		spawnBullet(sijainti);
		sijainti.y = 40.0f;
		spawnBullet(sijainti);
		fireTimer = FIRE_INTERVAL;
	}
}

void Player::spawnBullet(const Vector2f& sijainti) // ei toimi vielä asjgaga
{
	GameObject bullet(bullet_text);
	const IntRect textureRectangle(0, 119, 50, 10);
	bullet.setTextureRectangle(textureRectangle);
	bullet.setPosition(_player.position() + sijainti);
	bullet_list.push_back(bullet);
	//drawBullet(window);

}

void Player::drawBullet(RenderWindow* window) // i have no idea what i'm doing D:
{
	for (it = bullet_list.begin(); it != bullet_list.end(); it++)
		it->render(window);
}

void Player::updateBullet(const float deltaTime)
{
	Vector2f bulletPos;
	static const float BULLET_SPEED = 1500.0f;


	for (it = bullet_list.begin(); it != bullet_list.end(); it++)
	{
		bulletPos = it->position();
		bulletPos.y += BULLET_SPEED * deltaTime;
		it->setPosition(bulletPos);

		if (bulletPos.y > 1000 | bulletPos.y < 0)
		{
			it = bullet_list.erase(it);
		}
		else
		{
			it++;
		}
	}
}