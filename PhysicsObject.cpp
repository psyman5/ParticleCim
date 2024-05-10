#include "PhysicsObject.h"
#include "Vec2D.h"
#include "subVectors.h"
#include "addVectors.h"
#include "multByScalar.h"
#include "SFML/Graphics.hpp"

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

float PhysicsObject::getRadius() const {
	return radius;
};

void PhysicsObject::accelerate(Vec2D& accelerationVector) {

	updateAcceleration(accelerationVector);
};

void PhysicsObject::update(float dt) {
	Vec2D currentPos{ getCurrentPosition() };
	Vec2D oldPos{ getLastPos() };

	Vec2D velocityVector{ subVectors(currentPos, oldPos) };

	updateLastPos(currentPos);

	Vec2D accelVector{ multByScalar(getAcceleration(), (dt * dt)) };

	updateCurrentPosition(addVectors(addVectors(currentPos, velocityVector), accelVector));

	Vec2D blank{ 0, 0 };

	updateAcceleration( blank );
};

void PhysicsObject::applyConstraints(sf::Vector2u winSize , float radius) {
	Vec2D velocityVector{ subVectors(getCurrentPosition(), getLastPos()) };
	Vec2D currentPosition{ getCurrentPosition() };

	/*if ((currentPosition.getX() - radius < 0) or (currentPosition.getX() + radius > winSize.x)) {
		if (currentPosition.getX() - radius < 0) {
			Vec2D newPos{0 + radius, currentPosition.getY()};
			updateCurrentPosition(newPos);
			updateLastPos(addVectors(getCurrentPosition(), velocityVector) );

		}
		else if (currentPosition.getX() + radius > winSize.x) {
			Vec2D newPos{ static_cast<float>(winSize.x) - radius, currentPosition.getY()};
			updateCurrentPosition(newPos);
			updateLastPos(addVectors(getCurrentPosition(), velocityVector));
		};
	};
	if ((currentPosition.getY() - radius < 0) or (currentPosition.getY() + radius > winSize.y)) {
		if (currentPosition.getY() - radius < 0) {
			Vec2D newPos{ currentPosition.getX(), 0 + radius };
			updateCurrentPosition(newPos);
			updateLastPos(addVectors(getCurrentPosition(), velocityVector));

			return;

		}
		else if (currentPosition.getY() + radius > winSize.y) {
			Vec2D newPos{ currentPosition.getX(), static_cast<float>(winSize.y) - radius };
			updateCurrentPosition(newPos);
			updateLastPos(addVectors(getCurrentPosition(), velocityVector));
		};

	return;

	}; */

	if ((currentPosition.getX() - radius < 0) or (currentPosition.getX() + radius > winSize.x)) {
		if (currentPosition.getX() - radius < 0) {
			Vec2D newPos{0 + radius, currentPosition.getY()};
			updateCurrentPosition(newPos);
			updateLastPos(newPos);
		}
		else if (currentPosition.getX() + radius > winSize.x) {
			Vec2D newPos{ static_cast<float>(winSize.x) - radius, currentPosition.getY()};
			updateCurrentPosition(newPos);
			updateLastPos(newPos);
		};
	};
	if ((currentPosition.getY() - radius < 0) or (currentPosition.getY() + radius > winSize.y)) {
		if (currentPosition.getY() - radius < 0) {
			Vec2D newPos{ currentPosition.getX(), 0 + radius };
			updateCurrentPosition(newPos);
			
			return;

		}
		else if (currentPosition.getY() + radius > winSize.y) {
			Vec2D newPos{ currentPosition.getX(), static_cast<float>(winSize.y) - radius };
			updateCurrentPosition(newPos);
			
			return;
		};
	return;
	}; 
};

PhysicsObject* PhysicsObject::getPointer() {
	return this;
};

void PhysicsObject::doCollisions(std::vector<PhysicsObject>& objectVector, float coeffElast) { // TODO: Fix disappearing balls (check for valid positions before adjusting)

	PhysicsObject* physObjPointer{ getPointer() };

	for (int j{ 0 }; j < objectVector.size(); j++) {

		PhysicsObject& collisionPartner{ objectVector[j] };

		PhysicsObject* collisionPartnerPointer{ &collisionPartner };

		if (collisionPartnerPointer != physObjPointer) {

			Vec2D distVector{ subVectors(getCurrentPosition(), collisionPartner.getCurrentPosition()) };

			float distanceMag{ distVector.magnitude() };

			float minimumDistance{ getRadius() + collisionPartner.getRadius() };

			if (distanceMag < minimumDistance * minimumDistance) {

				const float dist{ sqrt(distanceMag) };
				Vec2D normalizedDistanceVector{ multByScalar(distVector, 1 / dist) };
				const float mr1{ getRadius() / (getRadius() + collisionPartner.getRadius()) };
				const float mr2{ collisionPartner.getRadius() / (getRadius() + collisionPartner.getRadius()) };
				const float del{ 0.5f * coeffElast * (minimumDistance - dist) };
				Vec2D separationVector{ multByScalar(normalizedDistanceVector, del) };

				updateCurrentPosition(addVectors(getCurrentPosition(), multByScalar(separationVector, mr2)));
				collisionPartner.updateCurrentPosition(subVectors(collisionPartner.getCurrentPosition(), multByScalar(separationVector, mr1)));
			};
		};
	};
};

void PhysicsObject::updateSubstep(float dt, int numSubsteps) {
	float subStepDt = dt / numSubsteps;
	for (int i = 0; i < numSubsteps; i++) {
		Vec2D currentPos{ getCurrentPosition() };
		Vec2D oldPos{ getLastPos() };

		Vec2D velocityVector{ subVectors(currentPos, oldPos) };

		updateLastPos(currentPos);

		Vec2D accelVector{ multByScalar(getAcceleration(), (subStepDt * subStepDt)) };

		updateCurrentPosition(addVectors(addVectors(currentPos, velocityVector), accelVector));
	}
}