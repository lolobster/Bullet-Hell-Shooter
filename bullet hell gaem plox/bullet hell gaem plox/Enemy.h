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
	// Constructor
	Enemy(Vector2f& pos_start, Vector2f pos_waypoint,
		TextureManager& texMgr);

	//Enemy(const Enemy&);
	//Enemy& operator=(const Enemy&);

	// Destructor
	~Enemy() { }

	// Methods
	Sprite getSprite() { return spr_enemy; }
	Vector2f getPosition(){ return position; }
	void draw(RenderWindow* window) { window->draw(spr_enemy); }
	void update(Time& elapsed);
	void shoot();
	void onHit();
private:
	const double PI = 3.141592653589793238463;
	int health;

	float speed = 5;
	float distance;
	float angle;
	float rotation;

	//std::vector<Enemy> hostiles;
	//std::vector<Enemy>::iterator ene_it;

	std::vector<Bullet> enemy_bullets;

	Vector2f position;
	Vector2f velocity;

	Sprite spr_enemy;
	Texture tex_enemy;

};