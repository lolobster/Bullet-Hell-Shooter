#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameObject
{
public:
	GameObject(int health);
	//float setPosX;
	//float setPosY;
	float speed;
	sf::Vector2f position() const;

	void setPosition(const sf::Vector2f& value);  // vektori sisältää positionit
	virtual void update(sf::RenderWindow &window, float elapsedTime);
	virtual void textureManager();
	virtual void render(sf::RenderWindow* window);  //renderöinti
	virtual~GameObject();

protected:

	int health;
	sf::Vector2f _origin;
	sf::Sprite pl_sprite;
	sf::Texture pl_text;
	sf::Sprite bg_sprite;
	sf::Texture bg_text;
	sf::Sprite ene_sprite;
	sf::Texture ene_text;
};

#endif