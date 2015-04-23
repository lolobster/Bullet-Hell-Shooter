#ifndef GAME_H
#define GAME_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

class Game
{
public:
	Game();
	void update(Time &elapsed);
	void render(RenderWindow* window);
	void spawnBullet(const Vector2f& sijainti);
	void updateBullet(const Time& elapsedTime);

	std::vector<Sprite> bullet_vec;		// list johon laitetaan bulletteja
	std::vector<Sprite>::iterator it;		// piirtoa varten

	~Game();
};

#endif