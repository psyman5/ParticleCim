#include "PhysicsObject.h"
#include <vector>
#include "verletIntegrator.h"
#include "SFML/Graphics.hpp"
#include "doCollision.h"
#include "SFML/Window.hpp"
#include <iostream>

void updateSim(float dt, std::vector<PhysicsObject>& objectVector, std::vector<sf::CircleShape>& shapeVector, sf::Vector2u winSize) {

	float grav{98};

	Vec2D gravity{grav/dt, 0};

	for (int i = 0; i < objectVector.size(); i++) {

		objectVector[i].accelerate(gravity);


		std::cout << "CD " << objectVector[i].getCurrentPosition().getX() << ", " << objectVector[i].getCurrentPosition().getY()
			<< " LP: " << objectVector[i].getLastPos().getX() << ", " << objectVector[i].getLastPos().getY()
			<< " Velo: " << objectVector[i].getCurrentPosition().getX() - objectVector[i].getLastPos().getX() << ", " << objectVector[i].getCurrentPosition().getY() - objectVector[i].getLastPos().getY()
			<< std::endl;

		doIntegration(dt, objectVector[i]);

		std::cout << "IS " << objectVector[i].getCurrentPosition().getX() << ", " << objectVector[i].getCurrentPosition().getY()
			<< " LP: " << objectVector[i].getLastPos().getX() << ", " << objectVector[i].getLastPos().getY()
			<< " Velo: " << objectVector[i].getCurrentPosition().getX() - objectVector[i].getLastPos().getX() << ", " << objectVector[i].getCurrentPosition().getY() - objectVector[i].getLastPos().getY()
			<< std::endl;


		doCollision(objectVector[i], shapeVector[i], winSize);
	};

};



