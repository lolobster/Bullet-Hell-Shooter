#include "GameObject.h"
//#include "SFML/Window/Event.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

class Player: public GameObject
{
public:
	Player();
	~Player();

	void onHit();
	void playerController(float deltaTime);
	void shoot(float, float);

private:
	int health;
	int deaths;
	float speed;

	//Buttons
	sf::Mouse::Button btn_shoot = sf::Mouse::Left;
	sf::Mouse::Button btn_use = sf::Mouse::Right;

	//Keys
	sf::Keyboard::Key kb_forward = sf::Keyboard::W;
	sf::Keyboard::Key kb_reverse = sf::Keyboard::S;
	sf::Keyboard::Key kb_left = sf::Keyboard::A;
	sf::Keyboard::Key kb_right = sf::Keyboard::D;

	float posX;
	float posY;
};

