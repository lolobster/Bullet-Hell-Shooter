//SFML
//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

//Definitions
#define ITEMS_MAX 3

class Menu
{
public:
	Menu(float, float);
	~Menu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem() { return selectedItem; }
	
private:
	int selectedItem;
	sf::Font font;
	sf::Text menu[ITEMS_MAX];
	void setupMenu(float w, float h, int s, std::string l);
	sf::Sprite bg_sprite;
	sf::Texture bg_text;
};

