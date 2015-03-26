#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Menu.h"

using namespace sf;

static void loop(RenderWindow& window);
void menu(RenderWindow& window);


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
	bool paused = 0;
	Event event;
	sf::Texture texture;
	sf::Clock clock;
	sf::Time updateGame = sf::milliseconds(10);

	Player play; // pointteri pleijerille EIKÄ OLE POINTTERI

	play.textureManager(); // lataa tekstuurit
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) // ajaa ohjelmaa niin kauan kuin ikkuna on auki
	{
		sf::Time elapsed = clock.restart();
		updateGame += elapsed;

		
		play.playerController(elapsed.asMilliseconds());

		while (window.pollEvent(event))
		{
			if (paused) // kato toimiiko
				continue;
			{

				switch (event.type) // tarkistaa ikkunan eventit joka looppauksella
				{
				case sf::Event::Closed: // ikkuna suljetaan
				{

					window.close();
					break;
				}
				case sf::Event::LostFocus:
				{
					paused = true;
				}
				case sf::Event::GainedFocus:
				{
					paused = false;
				}

				default: // määrittämätöntä eventtiä ei prosessoida
				{
					break;
				}
				}


				play.render(&window); //piirtää

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
			case sf::Event::Closed: // ikkuna suljetaan
			{

				window.close();
				break;
			}
			case sf::Event::KeyPressed: // nappulaa painetaan
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
				{
					menu.moveUp();
					break;
				}
				case sf::Keyboard::Down:
				{
					menu.moveDown();
					break;
				}
				case sf::Keyboard::Return:
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
			window.clear(sf::Color::Black);
			menu.draw(window);
			window.display();
		}
	}
}