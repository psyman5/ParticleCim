#include "Vec2D.h"
#include "dotProd2D.h"

float dotProd2D(const Vec2D& a, const Vec2D& b) {
	//dot product of 2 2D vector objects, returns scalar value

	return a.getX() * b.getX() + a.getY() * b.getY();
};