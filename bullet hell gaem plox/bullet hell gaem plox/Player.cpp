#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <sstream>

using namespace sf;

Player::Player(Vector2f pos, TextureManager& texMgr)
	: GameObject(health)
{

	positionPlayer = pos;

	pl_sprite.setTexture(texMgr.getRef("player"));

	if (!buffer.loadFromFile("sfx/laser1.wav"))
	{
		std::cout << "FILE NOT FOUND: sfx_shoot" << std::endl;
	}
	sfx_shoot.setBuffer(buffer);
	font.loadFromFile("arial.ttf");

}



Player::~Player()
{
}

void Player::updatePlayer(const Time& elapsedTime)
{
	const float elapsed = elapsedTime.asMicroseconds();

	updateBullet(elapsedTime);
	playerController(elapsed);
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
	direction.x = Mouse::getPosition().x;
	direction.y = Mouse::getPosition().y;

	static const float FIRE_INTERVAL = 250.0f;

	fireTimer -= elapsedTime;
	Vector2f sijainti = position();
	sijainti.x = position().x + 30.0f;
	//sijainti.y = -20.0f;
	if (fireTimer <= 0.0f)
	{
		Bullet *shot = new Bullet(sijainti, direction);

		sfx_shoot.play();

		bullet_vec.push_back(shot);
		fireTimer = FIRE_INTERVAL;
	}
}

void Player::onHit()
{
	health -= 1;

	if (health == 0)  // plussaa death countteria ja resettaa playerin alkusijaintiin
	{
		deaths += 1;
		health = 3;

		// räjähdys

		positionPlayer.x = 950;
		positionPlayer.y = 800;
	}
}

void Player::scoreCounter()
{
	score += 150;
}

void Player::draw(RenderWindow* window)
{
	for (it = bullet_vec.begin(); it != bullet_vec.end(); it++)
	{
		window->draw( (*it)->getSprite() );
	}

	std::ostringstream ss;
	ss << "Score: " << score << std::endl << "Health: " << getHealth() << std::endl << "Deaths: " << getDeaths();

	Text atext;
	atext.setFont(font);
	atext.setCharacterSize(20);
	atext.setStyle(sf::Text::Bold);
	atext.setColor(sf::Color::Green);
	atext.setPosition(1770, 0);
	atext.setString(ss.str());

	window->draw(atext);

}

void Player::updateBullet(const Time& elapsedTime)
{

	const float elapsed = elapsedTime.asMicroseconds();

	Vector2f bulletPos;

	for (it = bullet_vec.begin(); it != bullet_vec.end();)
	{
		(*it)->updateBullet();

		bulletPos = (*it)->getSprite().getPosition();

		if (bulletPos.y > 1000 || bulletPos.y < 0 || bulletPos.x > 1900 || bulletPos.x < 0)
		{
			it = bullet_vec.erase(it);
		}
		else
		{
			++it;
		}
	}
}