// SFML
//#include "SFML/Window/Event.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// C++
#include <iostream>
#include <list>

// Custom
#include "GameObject.h"
#include "Bullet.h"


using namespace sf;

class Player: public GameObject
{
public:
	Player(Vector2f);
	~Player();

	GameObject(bullet_text); // ei ehkä toimi

	void onHit();
	void updatePlayer(const Time& elapsedTime);
	void render(RenderWindow* window);
	void playerController(const float deltaTime);
	void shoot(const float deltaTime);

	std::list<GameObject> bullet_list;		// list johon laitetaan bulletteja
	std::list<GameObject>::iterator it;		// piirtoa varten
	std::vector<Bullet> vec_bullets;
	std::vector<Bullet>::iterator bullets_it;

	bool collision(Vector2f);

	void update();
private:
	int health;
	int deaths;
	float speed;

	//Texture bullet_text;
	GameObject _player;


	//Buttons
	Mouse::Button btn_shoot = Mouse::Left;
	Mouse::Button btn_use = Mouse::Right;

	//Keys
	Keyboard::Key kb_forward = Keyboard::W;
	Keyboard::Key kb_reverse = Keyboard::S;
	Keyboard::Key kb_left = Keyboard::A;
	Keyboard::Key kb_right = Keyboard::D;

	float posX;
	float posY;
	float fireTimer;

	float bottom, left, right, top;
	Vector2f pos_player;
	RectangleShape collisionBox;

};

