#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <list>

using namespace sf;

class GameObject
{
public:
	GameObject::GameObject() { }
	GameObject(int health);
	explicit GameObject(const sf::Texture& bullet_text);
	float speed;
	Vector2f position() const;
	//GameObject(*bullet_sprite); // ei ehkä toimi


	void setPosition(const Vector2f& value);
	void updateBackGround(float deltaTime);
	void setTextureRectangle(const IntRect& value);
	void shoot(const float deltaTime);
	void spawnBullet(const Vector2f& sijainti);
	void updateBullet(const float deltaTime);
	virtual void textureManager(float deltaTime);
	virtual void render(RenderWindow* window);
	virtual~GameObject();

	std::list<GameObject> bullet_list;		// list johon laitetaan bulletteja
	std::list<GameObject>::iterator it;		// piirtoa varten

protected:

	int health;
	float bgY;
	float bgX;
	float fireTimer;


	Vector2f _origin;
	Sprite pl_sprite;
	Texture pl_text;
	Sprite bg_sprite;
	Texture bg_text;
	Texture bullet_text;
	Sprite bullet_sprite;
	Sprite ene_sprite;
	Texture ene_text;
	Vector2f positionPlayer;

};

#endif