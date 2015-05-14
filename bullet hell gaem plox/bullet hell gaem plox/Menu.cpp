#include "Menu.h"
#include <iostream>


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//Handle error
		/*debug.printMessage("arial.ttf was not found");*/
	}


	setupMenu(width, height, 0, "Play");
	menu[0].setColor(sf::Color::Red);
	setupMenu(width, height, 1, "Options");
	setupMenu(width, height, 2, "Exit");

	selectedItem = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(bg_sprite);

	for (int i = 0; i < ITEMS_MAX; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setColor(sf::Color::Yellow);
		selectedItem--;
		menu[selectedItem].setColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedItem + 1 < ITEMS_MAX)
	{
		menu[selectedItem].setColor(sf::Color::Yellow);
		selectedItem++;
		menu[selectedItem].setColor(sf::Color::Red);
	}
}

void Menu::setupMenu(float width, float height, int spot, std::string label)
{
	float heightMp = spot + 0.3;
	menu[spot].setFont(font);
	menu[spot].setColor(sf::Color::Yellow);
	menu[spot].setString(label);
	menu[spot].setPosition(sf::Vector2f(width / 3, height / (ITEMS_MAX + 1) * heightMp));
	// items to right side -> (width / 1.3) 
	// items to left side -> (width / 13) 

	bg_text.loadFromFile("textures/menu_bg.png");
	bg_text.setSmooth(false);
	bg_sprite.setTexture(bg_text);
}
