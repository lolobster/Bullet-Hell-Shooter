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

	// methods
	void draw(sf::RenderWindow &w);
	void update();
	//void onHit(Bullet*);
	void loadTextures();
	void spawnBullet(const Vector2f& sijainti);
	void updateBullet(const Time& elapsedTime);

private:

	Texture bullet_text;
	Sprite bullet_sprite;
};
#endif