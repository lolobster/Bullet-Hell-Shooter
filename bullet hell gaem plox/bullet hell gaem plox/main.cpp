#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Menu.h"
#include "Enemy.h"
#include "TextureManager.h"

#include <algorithm>

TextureManager texMgr;

using namespace sf;

static void loop(RenderWindow& window);
void menu(RenderWindow& window);
void loadTextures();

std::vector<Enemy> hostiles;
std::vector<Enemy>::iterator it_h;

int main()
{
	float x = 1900; // original 600u / best 1920
	float y = 1000; // original 600u / best 1200
	RenderWindow window(VideoMode(x, y), "BULLET HELL SHOOTER 9000", sf::Style::Resize | sf::Style::Close/* | sf::Style::Titlebar*/); // asettaa ikkunan koon, muokattavissa
	menu(window);
	
	return 0;
}

static void loop(RenderWindow& window) // aliohjelma pyörittää ikkunaa
{
	srand(time(NULL));


	loadTextures();

	bool paused = 0;
	Event event;
	Texture texture;
	Clock clock;
	Time elapsedTime = clock.getElapsedTime();
	float elapsed = elapsedTime.asMicroseconds();

	/*GameObject game(texMan);*/
	GameObject game;
	Vector2f posP(950, 800);
	Player player(posP); 
	//Vector2f pos_start(800, 0);
	//Vector2f pos_waypoint(1700, 800);

	for (int i = 0; i < 10; i++)
	{
		Vector2f pos_start(rand()%1700, 0);
		Vector2f pos_waypoint(rand()%1700, 800);

		Enemy enemy(pos_start, pos_waypoint, texMgr);
		hostiles.push_back(enemy);
	}

	player.textureManager(elapsed); // lataa tekstuurit
	window.setVerticalSyncEnabled(false);

	while (window.isOpen()) // ajaa ohjelmaa niin kauan kuin ikkuna on auki
	{
		clock.restart();
		//updateGame += elapsed;

		player.updateBackGround(elapsed);
		player.playerController(elapsed);
		
		(window.pollEvent(event));  
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

				window.clear(Color::Black); // täyttää koko ikkunan mustalla värillä
				
				player.updatePlayer(elapsedTime);
				player.render(&window);

				it_h = std::remove_if(hostiles.begin(), hostiles.end(), [](){});

				for (int i = 0; i < hostiles.size(); i++)
				{
					hostiles.at(i).draw(&window);
					hostiles.at(i).update();
					
					if (player.getSprite().getGlobalBounds().
						intersects(hostiles[i].getSprite().getGlobalBounds()))
					{
						std::cout << "Collision!" << std::endl;
						hostiles.erase(hostiles.begin() + i);
					}
					
				}
				
				//for (it_h = hostiles.begin(); it_h != hostiles.end();)
				//{
				//	if (hostiles[i].getPos().y > 1000 | hostiles[i].getPos().y < 0)
				//	{
				//		hostiles.erase(it_h);
				//	}
				//}

				//enemy.draw(&window);
				//enemy.update();

				//if (player.getSprite().getGlobalBounds().
				//	intersects(enemy.getSprite().getGlobalBounds()))
				//{
				//	std::cout << "Collision!" << std::endl;

				//}

				window.display();
			}
		}
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

void loadTextures()
{
	texMgr.loadTexture("enemy", "textures/enemy.png");
	//texMgr.loadTexture("bullet", "textures/bullet.png");
}