#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#define _USE_MATH_DEFINES
#include "math.h"
#include "TextureManager.h"

using namespace sf;

class GameObject
{
public:
	GameObject::GameObject() { }
	GameObject(int health);
	float speed;
	Vector2f position() const;

	void loadBackground();
	void setPosition(const Vector2f& value);
	void updateBackGround(float deltaTime);
	void setTextureRectangle(const IntRect& value);
	
	//virtual void textureManager();
	virtual void render(RenderWindow* window);
	virtual~GameObject();

	std::vector<Sprite> bullet_vec;		// list johon laitetaan bulletteja
	std::vector<Sprite>::iterator it;		// piirtoa varten

protected:

	int health;
	float bgY;
	float fireTimer;
	float distance;

	Vector2f _origin;
	Sprite pl_sprite;
	Texture pl_text;
	Sprite bg_sprite;
	Texture bg_text;
	Sprite ene_sprite;
	Texture ene_text;
	Vector2f positionPlayer;
	Vector2f pos_target;
};

#endif