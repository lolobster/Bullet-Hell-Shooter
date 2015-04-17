#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Menu.h"
#include "Bullet.h"

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
	Texture texture;
	Clock clock;
	Time elapsedTime = clock.getElapsedTime();
	float elapsed = elapsedTime.asMicroseconds();

	GameObject game;
	Bullet bullet;
	Vector2f posP;
	posP.x = 950;
	posP.y = 800;
	Player play(posP); // pointteri pleijerille EIKÄ OLE POINTTERI
	//ei nii :DDDDD
	// kekekekekekek

	play.textureManager(); // lataa tekstuurit
	bullet.loadTextures();
	window.setVerticalSyncEnabled(false);

	while (window.isOpen()) // ajaa ohjelmaa niin kauan kuin ikkuna on auki
	{
		clock.restart();

		play.updateBackGround(elapsed);
		bullet.updateBullet(elapsedTime);
		play.updatePlayer(elapsedTime);

		(window.pollEvent(event));  // TÄMÄ PERKELE TÄSSÄ PISTI LIIKKUMAAAAANANANANANANA BÄTMÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄN
		{							// eli siis poistin while loopin
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


				


				play.render(&window);

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