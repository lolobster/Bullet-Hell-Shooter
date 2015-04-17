//#include "GameObject.h"

#include <SFML/Graphics/RectangleShape.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "TextureManager.h"

class Enemy
{
public:
	Enemy(const sf::Vector2f& pos_start, const sf::Vector2f& pos_waypoint, float angle, TextureManager& texMan);
	~Enemy();

	void onHit();
	void movement(float, float);
	void onDeath();
	void shoot();

	bool collision();

	//float bottom, top, left, right;
	void update();

	sf::Vector2f getPos();

	void draw(sf::RenderWindow* window);
	sf::Sprite getSprite() { return spr_enemy; }
private:
	int health;
	float speed;

	sf::RectangleShape collisionBox;

	sf::Vector2f pos_enemy;
	sf::Vector2f velocity;

	sf::Sprite spr_enemy;
	//sf::Texture tex_enemy;
	
};

