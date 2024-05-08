#include "Vec2D.h"
#include "multByScalar.h"

Vec2D multByScalar(const Vec2D& a, float b) {
	//multiplies a vector object by a scalar value, returns Vec2D, does not modify original vector


	Vec2D resultVector{ a.getX() * b, a.getY() * b };

	return resultVector;
};