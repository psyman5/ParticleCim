#include "PhysicsObject.h"
#include "Vec2D.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include "verletIntegrator.h"
#include "subVectors.h"
#include "addVectors.h"

void doCollision(PhysicsObject& obj, sf::CircleShape& shape, sf::Vector2u& winSize) { //TODO : PUT HEADER FILE + FINISH THIS TO TP THE BALLS OUT

	Vec2D currentPosition{ obj.getCurrentPosition()};
	float radius{ shape.getRadius() };
	Vec2D falseVelocityVector{subVectors(currentPosition, obj.getLastPos())};


	if ((currentPosition.getX() + radius > winSize.x) or (currentPosition.getX() < 0)) {

		if (currentPosition.getX() + radius > winSize.x) {

			Vec2D updatedPosition{ static_cast<float>(winSize.x) - radius, currentPosition.getY() };

			Vec2D updatedLastPosition{ currentPosition.getX() + falseVelocityVector.getX(), currentPosition.getY() };

			obj.updateCurrentPosition(updatedPosition);

			obj.updateLastPos(updatedLastPosition);

		}
		else if (currentPosition.getX() - radius < 0) {

			Vec2D updatedPosition{ 0, currentPosition.getY() };

			Vec2D updatedLastPosition{ currentPosition.getX() + falseVelocityVector.getX(), currentPosition.getY() };

			obj.updateCurrentPosition(updatedPosition);

			obj.updateLastPos(updatedLastPosition);

		};

	};

	if ((currentPosition.getY() > winSize.y) or (currentPosition.getY() < 0))
	{
		if (currentPosition.getY() + radius > winSize.y) {

			Vec2D updatedLastPosition{ currentPosition.getX(), currentPosition.getY() - 1 * falseVelocityVector.getY() };

			Vec2D updatedPosition{ currentPosition.getX(), static_cast<float>(winSize.y) - 20 * radius };

			

			//obj.updateCurrentPosition(updatedPosition);

			obj.updateLastPos(updatedLastPosition);

			return;
		}
		else if (currentPosition.getY() - radius < 0) {

			Vec2D updatedPosition{ currentPosition.getX(), 0 };

			Vec2D updatedLastPosition{ currentPosition.getX(), currentPosition.getY() + falseVelocityVector.getY() };

			obj.updateCurrentPosition(updatedPosition);

			obj.updateLastPos(updatedLastPosition);

			return;
		};

	};
	
	return;

};