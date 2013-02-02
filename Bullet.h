#ifndef BULLET_H
#define BULLET_H

#include "Object.h"

class Player;
class Asteroid;

class Bullet : public Object{
	const int range;
	Vector init;

	public:
	Bullet(const Player &p);
	void draw();
	bool collided(const Asteroid &a);
	bool isDead();
};

#endif
