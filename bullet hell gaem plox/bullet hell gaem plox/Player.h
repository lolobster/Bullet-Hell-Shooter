#include "GameObject.h"
#include "Bullet.h"
//#include "SFML/Window/Event.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include <list>

using namespace sf;

class Player : public GameObject
{
public:
	Player(Vector2f, TextureManager& texMgr);
	~Player();


	void onHit();
	void scoreCounter();
	void updatePlayer(const Time& elapsedTime);
	void playerController(const float deltaTime);
	void shoot(const float elapsedTime);
	void draw(RenderWindow* window);
	void updateBullet(const Time& elapsedTime);

	int getHealth(){ return health; }
	int getDeaths(){ return deaths; }

	Vector2f getPlayerPos(){ return positionPlayer; }
	Vector2f getBulletPos(){ return bulletPos; }

	std::list<Bullet*> bullet_vec;
	std::list<Bullet*>::iterator it;

	//void resizeVec()
	//{
	//	bullet_vec.resize(40, new Bullet());
	//}

	Sprite& getSprite() { return pl_sprite; }
	std::list<Bullet*> &getVector(){ return bullet_vec; }
	std::list<Bullet*>::iterator getIter(){ return it; }

private:
	int health = 5;
	int deaths;
	long score;

	SoundBuffer buffer;
	Sound sfx_shoot;

	Font font;

	Vector2f bulletPos;
	Vector2f direction;

	//Buttons
	Mouse::Button btn_shoot = Mouse::Left;
	Mouse::Button btn_use = Mouse::Right;

	//Keys
	Keyboard::Key kb_forward = Keyboard::W;
	Keyboard::Key kb_reverse = Keyboard::S;
	Keyboard::Key kb_left = Keyboard::A;
	Keyboard::Key kb_right = Keyboard::D;

	TextureManager texMgr;

	bool dead = false;
	sf::Clock deathclock;
	sf::Time delay;
	float respawn_timer;
};