#include "Object.h"

void Vector::copy(Vector v){
	x = v.x;
	y = v.y;
	z = v.z;
}

void Vector::add(Vector v){
	x += v.x;
	y += v.y;
	z += v.z;
}

Object::Object(){};

Object::Object(double x, double y):screenX(x),screenY(y){}

void Object::move(void){
	loc.x = loc.x + vel.x;
	loc.y = loc.y + vel.y;
	if(loc.x < 0) loc.x = screenX;
	if(loc.x > screenX) loc.x = 0;
	if(loc.y < 0) loc.y = screenY;
	if(loc.y > screenY) loc.y = 0;
}
