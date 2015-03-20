#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GameObject.h"
#include "Player.h"

using namespace sf;

static void loop(RenderWindow& window);

int main()
{
	RenderWindow window(VideoMode(1200u, 1100u), "BULLET HELL SHOOTER 9000", sf::Style::Resize | sf::Style::Close/* | sf::Style::Titlebar*/); // asettaa ikkunan koon, muokattavissa
	loop(window);
	
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