#include "Player.h"


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


void Player::playerController(float deltaTime)
{
			sf::Mouse mouse;

			if (sf::Mouse::isButtonPressed(btn_shoot))
			{
				//posX = mouse.getPosition().x; // mouse position on X axis is aquired
				//posY = mouse.getPosition().y; // mouse position on Y axis is aquired

				//shoot(posX, posY); //begin shoot action
			}
			if (sf::Mouse::isButtonPressed(btn_use))
			{
				// add functions
			}

			// LIIKKEET //

			if (sf::Keyboard::isKeyPressed(kb_left))
			{
				// liikett� vasempaan
				posX -= +0.5 * deltaTime;
			}
			if (sf::Keyboard::isKeyPressed(kb_right))
			{
				// liikett� oikeaan
				posX += 0.5 * deltaTime;
			}
			if (sf::Keyboard::isKeyPressed(kb_forward))
			{
				// liikett� yl�sp�in
				posY -= 0.5 * deltaTime;
			}
			if (sf::Keyboard::isKeyPressed(kb_reverse))
			{
				// liikett� alasp�in
				posY += 0.5 * deltaTime;
			}

			pl_sprite.setPosition(posX, posY);
}

void Player::shoot(float, float)
{

}
