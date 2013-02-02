#include <cmath>
#include <GL/glfw.h>
#include "Object.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

Bullet::Bullet(const Player &p):range(100){
	init.x = p.loc.x;
	init.y = p.loc.y;
	init.z = 0;
	loc.copy(init);
	vel.x = p.nose.x * 5;
	vel.y = p.nose.y * 5;
	vel.z = 0;
	screenX = 640;
	screenY = 480;
}

void Bullet::draw(){
	glBegin(GL_POINTS);
		glColor3f(1.0,1.0,1.0);
		glPointSize(5.0);
		glVertex2f(loc.x,loc.y);
	glEnd();
}

bool Bullet::collided(const Asteroid &rock){
	double x,y,s;
	rock.xysInfo(x,y,s);
	if(pow(loc.x - x,2) + pow(loc.y - y,2) > pow(s,2)) return false;
	return true;
}

bool Bullet::isDead(){
	if(pow(loc.x - init.x,2) + pow(loc.y - init.y,2) > pow(range,2)) return true;
	return false;
}
