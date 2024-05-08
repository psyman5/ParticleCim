#include "PhysicsObject.h"
#include <vector>
#include "verletIntegrator.h"
#include "SFML/Graphics.hpp"



void updateSim(float dt, std::vector<PhysicsObject>& objectVector, std::vector<sf::CircleShape>& shapeVector) {

	Vec2D gravity{0, 32.2}; 

	for (int i = 0; i < objectVector.size(); i++) {

		objectVector[i].accelerate(gravity);

		doIntegration(dt, objectVector[i]);
	};
};



