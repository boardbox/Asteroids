#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Asteroid;

class Player : public Object{
	double na;  //nose angle

	public:
	Vector nose;
	bool fired;

	Player();
	Player(double xInit, double yInit);
	void changeSpeed(double s);
	void rotate(double r);
	void draw();
	bool collided(const Asteroid &rock);
	~Player();
};

#endif
