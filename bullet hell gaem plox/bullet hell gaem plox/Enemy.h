#include "GameObject.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	void onHit();
	void movement(float, float);
	void onDeath();
	void shoot();

private:
	int health;
	float speed;
};

