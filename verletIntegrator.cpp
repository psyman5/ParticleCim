#include "PhysicsObject.h"
#include "Vec2D.h"
#include "addVectors.h"
#include "subVectors.h"
#include "dotProd2D.h"
#include "multByScalar.h"
#include <iostream>

void doIntegration(float dt, PhysicsObject& obj) {

	obj.updateLastPos(obj.getCurrentPosition());

	//part 1
	Vec2D xN{obj.getCurrentPosition()};
	Vec2D velocityVector{subVectors(obj.getCurrentPosition(), obj.getLastPos())};
	Vec2D acceleration{ multByScalar(obj.getAcceleration(), dt*dt) };
	
	obj.updateCurrentPosition(addVectors(addVectors(xN, velocityVector), acceleration));

	Vec2D accelReset{ 0,0 };

	obj.updateAcceleration( accelReset );

	return;
};