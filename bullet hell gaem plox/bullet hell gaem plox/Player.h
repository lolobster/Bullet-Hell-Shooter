#include "GameObject.h"
#include "Bullet.h"
//#include "SFML/Window/Event.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <list>

using namespace sf;

class Player : public GameObject
{
public:
	Player(Vector2f);
	~Player();


	void onHit();
	void updatePlayer(const Time& elapsedTime);
	void playerController(const float deltaTime);
	void shoot(const float elapsedTime);


private:
	int health;
	int deaths;

	Bullet bullet;

	Sprite* pl_sprite;

	//Buttons
	Mouse::Button btn_shoot = Mouse::Left;
	Mouse::Button btn_use = Mouse::Right;

	//Keys
	Keyboard::Key kb_forward = Keyboard::W;
	Keyboard::Key kb_reverse = Keyboard::S;
	Keyboard::Key kb_left = Keyboard::A;
	Keyboard::Key kb_right = Keyboard::D;

};