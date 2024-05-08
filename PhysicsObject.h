#pragma once
#include "Vec2D.h"

#ifndef PHYSICS_OBJECT
#define PHYSICS_OBJECT
#endif

class PhysicsObject
{
private:
	Vec2D currentPosition;
	Vec2D lastPos;
	Vec2D acceleration;

public:

	PhysicsObject(Vec2D currentPosition, Vec2D lastPos, Vec2D acceleration) : currentPosition{ currentPosition }, lastPos{ lastPos }, acceleration{ acceleration } {};

	void updateCurrentPosition(Vec2D newPosition);

	void updateLastPos(Vec2D newLastPos);

	void updateAcceleration(Vec2D acceleration);

	Vec2D getCurrentPosition() const;

	Vec2D getLastPos() const;

	Vec2D getAcceleration() const;

	void accelerate(Vec2D& accelerationVector);


};

