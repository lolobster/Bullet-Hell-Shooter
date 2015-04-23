#ifndef BULLET_H
#define BULLET_H

// SFML inclusions
#include <string>

// Custom inclusions
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet::Bullet() { }
	Bullet(Sprite bullet_sprite);
	~Bullet();

	//void loadTextures();
	//void spawnBullet(const Vector2f& sijainti);
	//void updateBullet(const Time& elapsedTime);


private:

};
#endif