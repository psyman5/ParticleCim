#pragma once
#ifndef UPDATE_SIM
#define UPDATE_SIM

#include <vector>
#include "PhysicsObject.h"
#include "SFML/Graphics.hpp"


void updateSim(float dt, std::vector<PhysicsObject>& objectVector, std::vector<sf::CircleShape>& shapeVector, sf::Vector2u winSize);
#endif // !1
