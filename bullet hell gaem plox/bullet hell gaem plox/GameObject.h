#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "Game.h"

using namespace sf;

class GameObject
{
public:
	GameObject::GameObject() { }
	GameObject(int health);
	float speed;
	Vector2f position() const;


	void setPosition(const Vector2f& value);
	void updateBackGround(float deltaTime);
	void setTextureRectangle(const IntRect& value);
	
	//virtual void textureManager();
	virtual~GameObject();



protected:

	int health;
	float bgY;
	float bgX;
	float fireTimer;

	Sprite* bg_sprite;

	Vector2f _origin;
	Vector2f positionPlayer;

private:
	Game* game;

};

#endif