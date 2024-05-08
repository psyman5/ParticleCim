#include "PhysicsObject.h"
#include "Vec2D.h"
#include "SFML/Graphics.hpp"
#include <cmath>

void doCollision(PhysicsObject& obj, sf::Vector2u winSize) { //TODO : PUT HEADER FILE + FINISH THIS TO TP THE BALLS OUT

	Vec2D center{ static_cast<float>(winSize.x / 2) , static_cast<float>(winSize.y / 2) }; // distance from center

	double distance{
		sqrt(
			pow(obj.getCurrentPosition().getX(),2) - pow(center.getX(),2) +
			pow(obj.getCurrentPosition().getY(),2) - pow(center.getY(),2)) };
};