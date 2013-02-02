#include <cstdio>
#include <cmath>
#include <GL/glfw.h>
#include "Player.h"
#include "Asteroid.h"

const double ph = 20;	//player height
const double pw = 10;	//player width
const double PI = 4.0*atan(1.0);

Player::Player():fired(false){
	loc.x = 0;
	loc.y = 0;
	loc.z = 0;
	vel.copy(loc);
	nose.copy(loc);
	nose.y += 1;
}

Player::Player(double xInit, double yInit):Object(xInit,yInit),na(PI/2),fired(false){
	loc.x = xInit / 2;
	loc.y = yInit / 2;
	loc.z = 0;
	vel.x = vel.y = vel.z = 0;
	nose.x = cos(na);
	nose.y = sin(na);
	nose.z = 0;
}

void Player::changeSpeed(double s){
	double newvx = vel.x + (nose.x * s);
	double newvy = vel.y + (nose.y * s);
	if(newvx*newvx < 9) vel.x = newvx;
	if(newvy*newvy < 9)	vel.y = newvy;
}

void Player::rotate(double r){
	na += r * PI/180;
	nose.x = cos(na);
	nose.y = sin(na);
}

//draws player based on location and ph/pw
void Player::draw(void){
	//get vertices
	Vector top;
	top.x = loc.x + (nose.x * ph * 0.5);
	top.y = loc.y + (nose.y * ph * 0.5);
	top.z = 0; //2d game, not used

	Vector bnorm; //unit normal parallel to base
	bnorm.z = 0.0;
	bnorm.x = 1.0 / ((-1.0 * pow(nose.x,2) / nose.y) - nose.y);
	bnorm.y = (-1.0 * nose.x * bnorm.x) / nose.y;

	Vector b1; //first base vertex
	b1.x = loc.x - (nose.x * ph * 0.5) + (bnorm.x * pw * 0.5);
	b1.y = loc.y - (nose.y * ph * 0.5) + (bnorm.y * pw * 0.5);
	b1.z = 0;

	Vector b2; //other base vertex
	b2.x = loc.x - (nose.x * ph * 0.5) - (bnorm.x * pw * 0.5);
	b2.y = loc.y - (nose.y * ph * 0.5) - (bnorm.y * pw * 0.5);
	b2.z = 0;

	glBegin(GL_TRIANGLES);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(top.x,top.y);
		glVertex2f(b1.x,b1.y);
		glVertex2f(b2.x,b2.y);
	glEnd();
}

bool Player::collided(const Asteroid &rock){
	double x,y,s;
	rock.xysInfo(x,y,s);
	double ref = s/2;
	if((x < loc.x - ref) || (x > loc.x + ref)) return false; //too far away
	if((y < loc.y - ref) || (y > loc.y + ref)) return false;

	if(pow(loc.x - x,2) + pow(loc.y - y,2) > pow(s,2)) return false;

	fprintf(stderr,"Player: %f %f, Rock: %f %f\n",loc.x,loc.y,x,y);
	return true; //assuming worst case
}
Player::~Player(){} //nothing to do
