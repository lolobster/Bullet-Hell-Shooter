#ifndef BULLET_H
#define BULLET_H

// SFML inclusions
#include <string>
#include <iostream>

// Custom inclusions
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet::Bullet(Vector2f pos, Vector2f pos_t);

	Bullet();
	~Bullet();

	void draw(RenderWindow& window);
	Sprite& getSprite() { return bullet_sprite; }
	void updateBullet();


private:

	float speed = 0.8f;
	float angle;

	Texture bullet_text;
	Sprite bullet_sprite;

	Vector2f velocity;
	Vector2f position;
};
#endif