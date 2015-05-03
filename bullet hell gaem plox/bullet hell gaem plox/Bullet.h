#ifndef BULLET_H
#define BULLET_H

// SFML inclusions
#include <string>

// Custom inclusions
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet::Bullet(Vector2f) { }
	Bullet();
	~Bullet();


	void loadTextures();
	void draw(RenderWindow& window);
	Sprite getSprite() { return bullet_sprite; }
	//void updateBullet(Time elapsedTime);

private:

	Texture bullet_text;
	Sprite bullet_sprite;
};
#endif