#ifndef ASTEROID_H
#define ASTEROID_H

#include "Object.h"

class Asteroid : public Object{
	double size;

	public:
	Asteroid(double x, double y, double scale, double vx, double vy, double xS, double yS);
	void draw();
	void xysInfo(double &x, double &y, double &s) const;
};

#endif
