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
		float angle, TextureManager& texMgr);

	// Deconstructor
	~Enemy() { }

	// Methods
	sf::Sprite getSprite() { return spr_enemy; }
	void draw(sf::RenderWindow* window) { window->draw(spr_enemy); }
	void update();
	void shoot();

	// public variables
	float bottom, top, left, right;

private:
	int health;
	float speed = 9001;

	std::vector<Bullet> bullets;

	sf::Vector2f position;
	sf::Vector2f movement;

	sf::Sprite spr_enemy;
	sf::Texture tex_enemy;
	
};

