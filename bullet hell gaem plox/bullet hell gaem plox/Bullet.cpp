#include "Bullet.h"
#include "Player.h"
#include <iostream>

Bullet::Bullet()
	: GameObject(health)
{

}

Bullet::~Bullet()
{
}

void Bullet::loadTextures()
{
	bullet_text.loadFromFile("bullet.png");
	bullet_text.setSmooth(true);// tasoittaa reunat
	bullet_sprite.setTexture(bullet_text);
	bullet_sprite.setScale(Vector2f(0.15f, 0.1f));
	bullet_sprite.setRotation(270);
	if (!bullet_text.loadFromFile("bullet.png"))
		std::cout << "noooooooooooooo";
}

void Bullet::draw(RenderWindow& window)
{
	std::cout << bullet_sprite.getPosition().x << ", " << bullet_sprite.getPosition().y << std::endl;

	window.draw(bullet_sprite); // ei saa oikeeta sijaintai eikä päivitä :((((( niin paljon leukoja
}

//void Bullet::onHit(Bullet *bullet)
//{
//	delete bullet;
//}