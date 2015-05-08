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
	Bullet::Bullet(Vector2f pos ) { 
		
		loadTextures();
	
		bullet_sprite.setPosition(pos);

		
	}
	Bullet();
	~Bullet();


	void loadTextures();
	void draw(RenderWindow& window);
	Sprite& getSprite() { return bullet_sprite; }

private:

	Texture bullet_text;
	Sprite bullet_sprite;
};
#endif