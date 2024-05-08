#include "PhysicsObject.h"
#include "Vec2D.h"

void PhysicsObject::updateCurrentPosition(Vec2D newPosition) {
	this->currentPosition = newPosition;
};

void PhysicsObject::updateLastPos(Vec2D newLastPos) {
	this->lastPos = newLastPos;
};

void PhysicsObject::updateAcceleration(Vec2D acceleration) {
	this->acceleration = acceleration;
};

Vec2D PhysicsObject::getCurrentPosition() const {
	return currentPosition;
};


Vec2D PhysicsObject::getLastPos() const {
	return lastPos;
};


Vec2D PhysicsObject::getAcceleration() const {
	return acceleration;
};

void PhysicsObject::accelerate(Vec2D& accelerationVector) {

	updateAcceleration(accelerationVector);
};