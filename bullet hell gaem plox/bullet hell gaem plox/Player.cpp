#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "GameObject.h"
#include "TextureManager.h"

using namespace sf;

Player::Player(Vector2f pos, TextureManager& texMgr)
	: GameObject(health)
{

	positionPlayer = pos;

	pl_sprite.setTexture(texMgr.getRef("player"));

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
		// liikett� vasempaan
		positionPlayer.x -= 0.24 * elapsedTime;
	}
	if (Keyboard::isKeyPressed(kb_right))
	{
		// liikett� oikeaan
		positionPlayer.x += 0.24 * elapsedTime;
	}
	if (Keyboard::isKeyPressed(kb_forward))
	{
		// liikett� yl�sp�in
		positionPlayer.y -= 0.15 * elapsedTime;
	}
	if (Keyboard::isKeyPressed(kb_reverse))
	{
		// liikett� alasp�in
		positionPlayer.y += 0.15 * elapsedTime;
	}

	pl_sprite.setPosition(positionPlayer);
}

void Player::shoot(const float elapsedTime)
{
	static const float FIRE_INTERVAL = 200.0f;

	fireTimer -= elapsedTime;
	Vector2f sijainti = position();
	sijainti.x = position().x + 30.0f;
	//sijainti.y = -20.0f;
	if (fireTimer <= 0.0f)
	{
		Bullet *shot=new Bullet(sijainti);
		
		
		//shot->loadTextures();
		bullet_vec.push_back(shot);
		fireTimer = FIRE_INTERVAL;
	}
}

void Player::draw(RenderWindow* window)
{
	for (it = bullet_vec.begin(); it != bullet_vec.end(); it++)
	{
		window->draw( (*it)->getSprite() );
	}
}

void Player::updateBullet(const Time& elapsedTime)
{

	const float elapsed = elapsedTime.asMicroseconds();

	Vector2f velocity;
	static const float BULLET_SPEED = 1.0f;


	for (it = bullet_vec.begin(); it != bullet_vec.end();)
	{

		bulletPos = (*it)->getSprite().getPosition();

		velocity.y = BULLET_SPEED * elapsed;
		
		bulletPos.y -= velocity.y;


		(*it)->getSprite().setPosition( bulletPos );

		++it;
	}
}