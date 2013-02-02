#ifndef OBJECT_H
#define OBJECT_H
struct Vector{
	double x;
	double y;
	double z;

	void copy(Vector v);
	void add(Vector v);
};

class Object{
	public:
	Vector loc;
	Vector vel;
	double screenX;
	double screenY;
	
	Object();
	Object(double x, double y);
	void move();
};

#endif
