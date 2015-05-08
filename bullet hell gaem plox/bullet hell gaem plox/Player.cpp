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

	collisionBox.setPosition(pos);
	//collisionBox.setSize();
	collisionBox.setFillColor(Color::Black);
}


Player::~Player()
{
}

void Player::updatePlayer(const Time& elapsedTime)
{
	const float elapsed = elapsedTime.asMicroseconds();
	playerController(elapsed);
	//updateBullet(elapsed);
}

void Player::update()
{

}

void Player::playerController(const float deltaTime)
{
			Mouse mouse;

			if (Mouse::isButtonPressed(btn_shoot))
			{
				shoot(deltaTime); //begin shoot action
			}
			if (Mouse::isButtonPressed(btn_use))
			{
				// add functions
			}

			// LIIKKEET //

			if (Keyboard::isKeyPressed(kb_left))
			{
				// liikett� vasempaan
				pos_player.x -= 0.24 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_right))
			{
				// liikett� oikeaan
				pos_player.x += 0.24 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_forward))
			{
				// liikett� yl�sp�in
				pos_player.y -= 0.15 * deltaTime;
			}
			if (Keyboard::isKeyPressed(kb_reverse))
			{
				// liikett� alasp�in
				pos_player.y += 0.15 * deltaTime;
			}
	
			//spr_player.setPosition(pos_player.x, pos_player.y);
			spr_player.setPosition(pos_player);
			update();
}

void Player::shoot(const float deltaTime)
{
//	static const float FIRE_INTERVAL = 0.1f;
//
//	fireTimer -= deltaTime;
//
//	Vector2f pos_target;
//	pos_target.x = 500;
//	pos_target.y = 1000;
//
//	if (fireTimer <= 0.0f)
//	{
//		Bullet bullet(pos_player, pos_target, 45);
//		bullet_list.push_back(bullet);
//		fireTimer = FIRE_INTERVAL;
//	}
//
//
//	static const float BULLET_SPEED = 1.0f;
//
//	
//	do
//	{
//		for (int i = 0; i < vec_bullets.size(); i++)
//		{
//			
//			vec_bullets.at(i).update();
//
//			if (vec_bullets.at(i).getPos().x < 0 || vec_bullets.at(i).getPos().y > 1000)
//			{
//				vec_bullets.erase(vec_bullets.begin()+i);
//			}
//		}
//
//	} while (!vec_bullets.empty());
}

void Player::onHit()
{
	health -= 1;

	if (health == 0)
	{
		deaths = +1;
	}
}