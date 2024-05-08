#include "Vec2D.h"
#include <cmath>

void Vec2D::setX(float x) {
	this->x = x;
};

void Vec2D::setY(float y) {
	this->y = y;
};

float Vec2D::getX() const {
	return x;
};


float Vec2D::getY() const {
	return y;
};

float Vec2D::magnitude() const {
	return sqrt( ( x * x ) + ( y * y) );
};
	