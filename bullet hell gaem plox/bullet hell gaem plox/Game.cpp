#include "Game.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Player.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::update(Time &elapsed)
{

}

void Game::render(RenderWindow* window)
{
	window->draw(bg_sprite);

	window->draw(pl_sprite);
	window->draw(ene_sprite);

	for (int i = 0; i < bullet_vec.size(); i++)
	{
		window->draw(bullet_vec[i]);
	}
}
void Game::spawnBullet(const Vector2f& sijainti) // ei toimi vielä asjgaga
{
	//Bullet bullet(bullet_sprite);
	//const IntRect textureRectangle(0, 119, 50, 10);
	//bullet.setTextureRectangle(textureRectangle);// tämä pitää muuttaa Playeriksi
	bullet_sprite->setPosition(sijainti);
	bullet_vec.push_back(bullet_sprite);
}

void Game::updateBullet(const Time& elapsedTime)
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