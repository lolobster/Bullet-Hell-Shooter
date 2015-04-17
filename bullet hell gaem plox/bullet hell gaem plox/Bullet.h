#ifndef BULLET_H
#define BULLET_H

// SFML inclusions
#include <string>

// Custom inclusions
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	//Bullet(/*int s, */float x, float y, float a);
	Bullet(const sf::Vector2f& startingPos, const sf::Vector2f& targetPos, float angle);
	virtual ~Bullet();

	// methods
	void draw(sf::RenderWindow &w);
	Vector2f getPos();
	void update();
	void onCollision();


private:
	sf::Vector2f pos_bullet;
	sf::Vector2f velocity;
	
	float speed = 100;
};
#endif

