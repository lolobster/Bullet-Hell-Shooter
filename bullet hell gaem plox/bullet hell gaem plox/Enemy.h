//#include "GameObject.h"

// SFML
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// C++
#include <vector>
// Custom
#include "GameObject.h"
#include "Bullet.h"

using namespace sf;

class Enemy : public GameObject
{
public:
	Enemy(Vector2f& pos_start, Vector2f pos_waypoint,
		TextureManager& texMgr);
	Enemy(){};

	~Enemy() { }

	// Methods
	Sprite getSprite() { return spr_enemy; }
	Vector2f getPosition(){ return position; }
	void draw(RenderWindow* window);
	void update(Time& elapsed);
	void shoot(const float elapsedTime);

	void updateBullet(const Time& elapsedTime);
private:
	int health;

	float speed = 5;
	float distance;
	float angle;

	//std::vector<Enemy> hostiles;
	//std::vector<Enemy>::iterator ene_it;

	std::vector<Bullet*> bullet_vec;
	std::vector<Bullet*>::iterator it;

	Vector2f position;
	Vector2f pos_direction;
	Vector2f velocity;

	Sprite spr_enemy;
	Texture tex_enemy;

};