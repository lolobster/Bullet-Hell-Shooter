#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
//#include <SFML/Graphics/Texture.hpp>
#include "TextureManager.h"
class Explosion
{
public:
	Explosion(TextureManager&, sf::Vector2f pos);
	~Explosion();
	void update(const sf::Time& elapsedTime);
	void draw(sf::RenderWindow* w);

	sf::Vector2i getFrame(){ return _currentFrame; }
private:
	const sf::Vector2i _frameCount;
	const sf::Vector2i _frameSize;

	sf::Vector2i _currentFrame;
	float _animationTime;
	float _frameDuration;
	
	sf::Sprite spr_explo;

};

