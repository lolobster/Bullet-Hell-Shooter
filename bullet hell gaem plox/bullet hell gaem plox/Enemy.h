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

class Enemy : public GameObject
{
public:
	// Constructor
	Enemy(const sf::Vector2f& pos_start, const sf::Vector2f pos_waypoint,
		TextureManager& texMgr);

	// Deconstructor
	~Enemy() { }

	// Methods
	sf::Sprite getSprite() { return spr_enemy; }
	void draw(sf::RenderWindow* window) { window->draw(spr_enemy); }
	void update();
	void shoot();
	void onHit();

	sf::Vector2f getPos() { return position; }

private:
	const double PI = 3.141592653589793238463;
	int health;
	
	float speed = 5;
	float distance;
	float angle;
	float rotation;

	std::vector<Bullet> bullets;

	sf::Vector2f position;
	sf::Vector2f velocity;

	sf::Sprite spr_enemy;
	sf::Texture tex_enemy;
	
};

