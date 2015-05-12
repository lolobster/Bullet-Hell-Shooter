#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "GameObject.h"

using namespace sf;

Player::Player(Vector2f pos)
	: GameObject(health)
{
	positionPlayer = pos;

	if (!buffer.loadFromFile("sfx/laser1.wav"))
	{
		std::cout << "FILE NOT FOUND: sfx_shoot" << std::endl;
	}
	sfx_shoot.setBuffer(buffer);
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

	direction.x = sf::Mouse::getPosition().x;
	direction.y = sf::Mouse::getPosition().y;

	static const float FIRE_INTERVAL = 200.0f;

	fireTimer -= elapsedTime;
	Vector2f sijainti = position();
	sijainti.x = position().x + 30.0f;
	//sijainti.y = -20.0f;
	if (fireTimer <= 0.0f)
	{
		Bullet *shot = new Bullet(sijainti, direction);

		sfx_shoot.play();
		//std::cout << "laukaus" << std::endl; // Testi

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

	Vector2f bulletPos;
	
	for (it = bullet_vec.begin(); it != bullet_vec.end();)
	{
		(*it)->updateBullet();

		bulletPos = (*it)->getSprite().getPosition();

		if (bulletPos.y > 1000 || bulletPos.y < 0)
		{
			it = bullet_vec.erase(it);
		}
		else
		{
			++it;
		}
	}
}