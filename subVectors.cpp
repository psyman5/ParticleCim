#include "Vec2D.h"
#include "subVectors.h"

Vec2D subVectors(const Vec2D& a, const Vec2D& b) {
	//subtract vector b from vector a, returns Vec2D object

	Vec2D result(a.getX() - b.getX(), a.getY() - b.getY());

	return result;
};