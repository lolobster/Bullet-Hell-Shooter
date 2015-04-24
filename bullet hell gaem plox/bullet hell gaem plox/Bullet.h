#ifndef BULLET_H
#define BULLET_H

// SFML
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

// C++
#include <string>

// Custom
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(const sf::Vector2f& pos_start, const sf::Vector2f& pos_target, float angle);
	~Bullet(){ }

	void update();

private:
	sf::Vector2f velocity;
	sf::Vector2f position;

	sf::Sprite spr_bullet;

	float distance;
	float speed = 100;
};
#endif

