#include "Vec2D.h"
#include "addVectors.h"

Vec2D addVectors(const Vec2D& a, const Vec2D& b) {
	// adds two vectors elementwise, returns Vec2D object

	Vec2D result(a.getX() + b.getX(), a.getY() + b.getY());

	return result;
};