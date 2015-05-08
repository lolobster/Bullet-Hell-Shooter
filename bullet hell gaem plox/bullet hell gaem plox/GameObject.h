#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

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
	virtual void textureManager(float deltaTime);
	virtual void render(RenderWindow* window);
	virtual~GameObject();

protected:

	int health;
	float bgY;
	float bgX;

	Vector2f _origin;
	Sprite pl_sprite;
	Texture pl_text;
	Sprite bg_sprite;
	Texture bg_text;
	Texture bullet_text;
	Sprite bullet_sprite;
	Sprite ene_sprite;
	Texture ene_text;
};

#endif