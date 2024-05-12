#pragma once
#include "Vec2D.h"
#include "SFML/Graphics.hpp"

#ifndef PHYSICS_OBJECT
#define PHYSICS_OBJECT
#endif

class PhysicsObject
{
private:
	Vec2D currentPosition;
	Vec2D lastPos;
	Vec2D acceleration;
	float radius;

public:

	PhysicsObject(Vec2D currentPosition, Vec2D lastPos, Vec2D acceleration, float radius) : currentPosition{ currentPosition }, lastPos{ lastPos }, acceleration{ acceleration }, radius{ radius } {};

	void updateCurrentPosition(Vec2D newPosition);

	void updateLastPos(Vec2D newLastPos);

	void updateAcceleration(Vec2D acceleration);

	Vec2D getCurrentPosition() const;

	Vec2D getLastPos() const;

	Vec2D getAcceleration() const;

	float getRadius() const;

	void accelerate(Vec2D& accelerationVector);

	void update(float dt);

	void applyConstraints(sf::Vector2u winSize, float radius);

	PhysicsObject* getPointer();

	void doCollisions(std::vector<PhysicsObject>& objectVector, float coeffElast, sf::Vector2u winSize);

	void updateSubstep(float dt, int numSubsteps);

	bool isInCorner(Vec2D position, float radius, sf::Vector2u windowSize);



};
	
