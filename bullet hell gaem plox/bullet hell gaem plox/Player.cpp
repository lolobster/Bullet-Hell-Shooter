#include "Player.h"
#include <algorithm>

using namespace sf;

Player::Player(Vector2f pos)
	: GameObject(health)
{
	/*pos_player.x = pos.x;
	pos_player.y = pos.y;*/
	pos_player = pos;

	//pos_player.x = spr_player.getPosition().x;
	//pos_player.y = spr_player.getPosition().y;
}


Player::~Player()
{
}

void Player::updatePlayer(const Time& elapsedTime)
{
	const float elapsed = elapsedTime.asMicroseconds();
	//playerController(elapsed);
	//updateBullet(elapsed);
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
			Vector2f playerPos(pos_player.x, pos_player.y);
			//playerPos = _player.position();

			if (Mouse::isButtonPressed(btn_shoot))
			{
				//pos_player.x = mouse.getPosition().x; // mouse position on X axis is aquired
				//pos_player.y = mouse.getPosition().y; // mouse position on Y axis is aquired

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
				pos_player.x -= 0.24 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_right))
			{
				// liikettä oikeaan
				pos_player.x += 0.24 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_forward))
			{
				// liikettä ylöspäin
				pos_player.y -= 0.15 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_reverse))
			{
				// liikettä alaspäin
				pos_player.y += 0.15 * deltaTime;
			}
	
			spr_player.setPosition(pos_player.x, pos_player.y);
}

void Player::shoot(const float deltaTime)
{
	static const float FIRE_INTERVAL = 0.1f;

	fireTimer -= deltaTime;

	Vector2f pos_target;
	pos_target.x = 500;
	pos_target.y = 1000;

	if (fireTimer <= 0.0f)
	{
		Bullet bullet(pos_player, pos_target, 45);
		bullet_list.push_back(bullet);
		fireTimer = FIRE_INTERVAL;
	}


	static const float BULLET_SPEED = 1.0f;

	
	do
	{
		for (int i = 0; i < vec_bullets.size(); i++)
		{
			
			vec_bullets.at(i).update();

			if (vec_bullets.at(i).getPos().x < 0 || vec_bullets.at(i).getPos().y > 1000)
			{
				vec_bullets.erase(vec_bullets.begin()+i);
			}
		}

	} while (!vec_bullets.empty());

	//Vector2f bulletPos;

	//for (it = bullet_list.begin(); it != bullet_list.end(); it++)
	//{
	//	do
	//	{
	//		//bullet_list.
	//		//bulletPos = pos_player;
	//		//bulletPos.y += BULLET_SPEED * deltaTime;
	//		//it->setPosition(bulletPos);

	//	} while (bulletPos.y > 1000 | bulletPos.y < 0);
	//	
	//	it = bullet_list.erase(it);	
	//}





	//Vector2f sijainti = pos_player;

	//if (fireTimer <= 0.0f)
	//{
	//	sijainti.y = -40.0f;
	//	spawnBullet(sijainti);
	//	sijainti.y = 40.0f;
	//	spawnBullet(sijainti);
	//	fireTimer = FIRE_INTERVAL;
	//}
}

//void Player::spawnBullet(const Vector2f& sijainti) // ei toimi vielä asjgaga
//{
//	GameObject bullet(bullet_text);
//	/*const IntRect textureRectangle(0, 119, 50, 10);
//	bullet.setTextureRectangle(textureRectangle);*/
//	/*bullet.setPosition(pos_player);*/
//	bullet_list.push_back(bullet);
//	/*drawBullet(bullet_list);*/
//}

void Player::render(RenderWindow* window) // i have no idea what i'm doing D:
{
	window->draw(spr_background);

	window->draw(spr_player);

	for (it = bullet_list.begin(); it != bullet_list.end(); it++)
		window->draw(spr_bullet);
}

//void Player::updateBullet(const float deltaTime)
//{
//	//Vector2f bulletPos;
//	//static const float BULLET_SPEED = 1.0f;
//
//
//	//for (it = bullet_list.begin(); it != bullet_list.end(); it++)
//	//{
//	//	do
//	//	{
//	//		bulletPos = pos_player;
//	//		bulletPos.y += BULLET_SPEED * deltaTime;
//	//		it->setPosition(bulletPos);
//
//	//	} while (bulletPos.y > 1000 | bulletPos.y < 0);
//	//	
//	//	it = bullet_list.erase(it);
//	//	
//	//}
//}