#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <time.h>
#include "GameObject.h"
#include "Player.h"
#include "Menu.h"
#include "Bullet.h"
#include "Enemy.h"
#include "TextureManager.h"

using namespace sf;
TextureManager texMgr;
static void loop(RenderWindow& window);
void menu(RenderWindow& window);
void loadTextures();

std::vector<Enemy> hostiles;
std::vector<Enemy>::iterator ene_it;
int size = hostiles.size();

int main()
{
	int x = 1900; // original 600u / best 1920
	int y = 1000; // original 600u / best 1200
	RenderWindow window(VideoMode(x, y), "BULLET HELL SHOOTER 9000", Style::Resize | Style::Close); // asettaa ikkunan koon, muokattavissa
	menu(window);

	return 0;
}

static void loop(RenderWindow& window) // aliohjelma pyörittää ikkunaa
{
	texMgr.loadTexture("enemy", "textures/base_enemy.png");
	texMgr.loadTexture("player", "textures/player.png");
	texMgr.loadTexture("bullet", "textures/bullet.png");

	bool paused = 0;
	Event event;
	Texture texture;
	Clock clock;
	Time elapsedTime = clock.getElapsedTime();
	float elapsed = elapsedTime.asMicroseconds();

	Clock enemyTimer;
	Time enemytime = enemyTimer.getElapsedTime();
	float timer = enemytime.asMicroseconds();

	//Time current = clock.getElapsedTime();
	//Time last_time = current;
	GameObject game;
	Bullet bul;
	Enemy *enemy= new Enemy();
	Vector2f posP;
	posP.x = 950;
	posP.y = 800;
	Player play(posP, texMgr);
	play.loadBackground();




	window.setVerticalSyncEnabled(false);

	while (window.isOpen())
	{
		clock.restart();

		play.updateBackGround(elapsed);
		play.updatePlayer(elapsedTime);


		while (window.pollEvent(event))
		{							
			if (paused)
				continue;
			{
				switch (event.type)
				{
				case Event::Closed:
				{
					window.close();
					break;
				}
				case Event::LostFocus:
				{
					paused = true;
				}
				case Event::GainedFocus:
				{
					paused = false;
				}
				default: // määrittämätöntä eventtiä ei prosessoida
				{
					break;
				}
				}
			}
		}


		//for (int i = 0; i < 20; i++)
		//{


			if (timer > 0 && size < 20)
			{
				Vector2f pos_start(rand() % 1700, 0);
				Vector2f pos_waypoint(rand() % 1700, 800);
				Enemy enemy(pos_start, pos_waypoint, texMgr);

				hostiles.push_back(enemy);
				enemyTimer.restart();
			}
	/*	}*/

		ene_it = hostiles.begin();

		while (ene_it != hostiles.end())
		{   // poistaa enemyn jos siihen osuu tai se on liikkunut ulos ruudusta
			

			std::vector<Bullet*>::iterator it = play.getVector().begin();
			bool hitEnemy = false;
			bool hitPlayer = false;

			while (it != play.getVector().end())
			{
				if ((*it)->getSprite().getGlobalBounds().
					intersects(ene_it->getSprite().getGlobalBounds()) || bul.getSprite().getPosition().y > 1000 ||
					bul.getSprite().getPosition().y < 0 || bul.getSprite().getPosition().x > 1900 || 
					bul.getSprite().getPosition().x < 0)
				{
					std::cout << "Collision!" << std::endl;
					it = play.getVector().erase(it);
					hitEnemy = true;
				}
				else
				{
					++it;
				}
			}
			if (play.getSprite().getGlobalBounds().
				intersects(ene_it->getSprite().getGlobalBounds()))
			{
				play.onHit();
				hitPlayer = true;
			}

			if (hitEnemy || hitPlayer || ene_it->getSprite().getPosition().y > 1000 ||
				ene_it->getSprite().getPosition().y < 0 || ene_it->getSprite().getPosition().x > 1900 || 
				ene_it->getSprite().getPosition().x < 0)
			{
				std::cout << "Collision!" << std::endl;
				ene_it = hostiles.erase(ene_it);
			}

			
			else
			{
				ene_it->update(elapsedTime);

				++ene_it;
			}
		}


		ene_it = hostiles.begin();

		window.clear(Color::Black);

		play.render(&window);
		
		play.draw(&window);

		
		for (ene_it = hostiles.begin(); ene_it != hostiles.end(); ene_it++)
		{
			ene_it->draw(&window);
		}

		window.display();

	}
}
void menu(RenderWindow& window)
{
	Event event;

	Menu menu(window.getSize().x, window.getSize().y);
	menu.draw(window);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type) // tarkistaa ikkunan eventit joka looppauksella
			{
			case Event::Closed: // ikkuna suljetaan
			{

				window.close();
				break;
			}
			case Event::KeyPressed: // nappulaa painetaan
			{
				switch (event.key.code)
				{
				case Keyboard::Up:
				{
					menu.moveUp();
					break;
				}
				case Keyboard::Down:
				{
					menu.moveDown();
					break;
				}
				case Keyboard::Return:
				{
					switch (menu.getPressedItem())
					{
					case 0:	//Menu item 0 (Play) gets pressed
					{	
						loop(window);
						break;
					}
					case 1: //Menu item 1 (Options) gets pressed
					{
						break;
					}
					case 2: //Menu item 2 (Exit) gets pressed
					{
						window.close();
						break;
					}
					}
					break;
				}
				}
				break;
			}

			default: // määrittämätöntä eventtiä ei prosessoida
			{
				break;
			}
			}
			window.clear(Color::Black);
			menu.draw(window);
			window.display();
		}
	}
}
