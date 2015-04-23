#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "GameObject.h"

using namespace sf;

Player::Player(Vector2f pos)
	: GameObject(health)
{
	/*positionPlayer.x = pos.x;
	positionPlayer.y = pos.y;*/
	positionPlayer = pos;

	//positionPlayer.x = pl_sprite.getPosition().x;
	//positionPlayer.y = pl_sprite.getPosition().y;
}


Player::~Player()
{
}

void Player::updatePlayer(const Time& elapsedTime)
{
	const float elapsed = elapsedTime.asMicroseconds();
	//playerController(elapsed);
	//if (Mouse::isButtonPressed())
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
	//Vector2f playerPos(positionPlayer.x, positionPlayer.y);
	//playerPos = _player.position();

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
		bullet.spawnBullet(sijainti);
		fireTimer = FIRE_INTERVAL;
	}
}