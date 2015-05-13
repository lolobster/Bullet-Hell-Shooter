#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
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

int main()
{
	int x = 1900; // original 600u / best 1920
	int y = 1000; // original 600u / best 1200
	RenderWindow window(VideoMode(x, y), "BULLET HELL SHOOTER 9000", sf::Style::Resize | sf::Style::Close/* | sf::Style::Titlebar*/); // asettaa ikkunan koon, muokattavissa
	menu(window);

	return 0;
}

//enum class GameState
//{
//	Game,
//	Menu
//};
//
//static void loop(RenderWindow& window)
//{
//	Menu menu;
//	Game game;
//	GameState gameState;
//	Event event;
//	Clock clock;
//	Time deltaTime;
//
//	while (window.isOpen())
//	{
//		clock.restart();
//
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//				case Event::Closed:
//					window.close();
//					break;
//
//				case Event::KeyPressed:
//					switch (gameState)
//					{
//					case Game:
//						game.handleInput(event.key.code);
//						break;
//
//					case Menu:
//						menu.handleInput(event.key.code);
//						break;
//					}
//
//					break;
//			}
//		}
//
//		deltaTime = clock.getElapsedTime();
//
//		switch (gameState)
//		{
//			case Game:
//				game.update(deltaTime, window);
//				break;
//
//			case Menu:
//				menu.update(deltaTime, window);
//				break;
//		}
//	}
//}

static void loop(RenderWindow& window) // aliohjelma pyörittää ikkunaa
{
	texMgr.loadTexture("enemy", "textures/base_enemy.png");
	texMgr.loadTexture("player", "textures/player.png");
	texMgr.loadTexture("explosion", "textures/sheet_explosion.png");

	bool paused = 0;
	Event event;
	Texture texture;
	Clock clock;
	Time elapsedTime = clock.getElapsedTime();
	float elapsed = elapsedTime.asMicroseconds();
	GameObject game;
	Bullet bul;
	Enemy *enemy= new Enemy();
	Vector2f posP;
	posP.x = 950;
	posP.y = 800;
	Player play(posP, texMgr);
	play.loadBackground();

	for (int i = 0; i < 10; i++)
	{
		Vector2f pos_start(rand() % 1700, 0);
		Vector2f pos_waypoint(rand() % 1700, 800);

		Enemy enemy(pos_start, pos_waypoint, texMgr);
		hostiles.push_back(enemy);
	}

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

		ene_it = hostiles.begin();

		while (ene_it != hostiles.end())
		{   // poistaa enemyn jos siihen osuu tai se on liikkunut ulos ruudusta
			

			std::vector<Bullet*>::iterator it = play.getVector().begin();
			bool hitEnemy = false;

			while (it != play.getVector().end())
			{
				if ((*it)->getSprite().getGlobalBounds().
					intersects(ene_it->getSprite().getGlobalBounds()) || bul.getSprite().getPosition().y > 1000 ||
					bul.getSprite().getPosition().y < 0)
				{
					std::cout << "Collision!" << std::endl;
					it = play.getVector().erase(it);
					hitEnemy = true;
					//ene_it = hostiles.erase(ene_it);
				}
				else
				{
					++it;
				}
			}
			if (hitEnemy || play.getSprite().getGlobalBounds().
				intersects(ene_it->getSprite().getGlobalBounds()) || enemy->getPosition().y > 1000 ||
				enemy->getPosition().y < 0)
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
				texMgr.~TextureManager();
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

void explosions()
{
	sf::Texture tex_explo;
	sf::Sprite spr_explo;

	spr_explo.setTexture(texMgr.getRef("explosion"));
	enum Explosion {};

	sf::Vector2i sheet(32, 32);
	
	//explosion.setTextureRect(sf::IntRect(sheet.x * 32, sheet.y * 32, 32, 32));
}
