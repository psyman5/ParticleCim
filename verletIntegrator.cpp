#include "PhysicsObject.h"
#include "Vec2D.h"
#include "addVectors.h"
#include "subVectors.h"
#include "dotProd2D.h"
#include "multByScalar.h"

void doIntegration(float dt, PhysicsObject& obj) {

	//Vec2D velocityVector{ subVectors( obj.getCurrentPosition() ,obj.getLastPos() ) };

	// verlet integration : currentPos = currentPos + velocity + acceleration * dt * dt

	obj.updateLastPos(obj.getCurrentPosition());

	obj.updateCurrentPosition(
		addVectors(
			addVectors(
				obj.getCurrentPosition(), subVectors(obj.getCurrentPosition(), obj.getLastPos()
				)
			),
		(multByScalar(obj.getAcceleration(), (dt * dt)))));

	Vec2D blank{ 0,0 };

	obj.updateAcceleration(blank);

	//TODO: make this look nicer and less intimidating

	return;
};