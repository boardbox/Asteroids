#include <GL/glfw.h>
#include "Object.h"
#include "Asteroid.h"

Asteroid::Asteroid(double x, double y, double scale, double vx, double vy, double xS, double yS)
	:Object(xS,yS),size(scale){
	loc.x = x;
	loc.y = y;
	loc.z = 0;
	vel.x = vx;
	vel.y = vy;
	vel.z = 0;
}

void Asteroid::draw(){
	glPushMatrix();
	glTranslatef(loc.x,loc.y,0);
	glScaled(size,size,1.0);
	
	glPushMatrix();
	glScaled(0.33333,0.33333,1.0);
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(-1.5,-0.5);
		glVertex2f(-1.5,+0.5);
		glVertex2f(-0.5,+1.5);
		glVertex2f(+0.5,+1.5);
		glVertex2f(+1.5,+0.5);
		glVertex2f(+1.5,-0.5);
		glVertex2f(+0.5,-1.5);
		glVertex2f(-0.5,-1.5);
	glEnd();
	glPopMatrix();
	//glScaled(1,1,1);
	glPopMatrix();
}

void Asteroid::xysInfo(double &x, double &y, double &s) const{
	x = loc.x;
	y = loc.y;
	s = size;
}
