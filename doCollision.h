#pragma once

#ifndef COLLISION_TEST
#define COLLISION_TEST

#include "PhysicsObject.h"
#include "SFML/Graphics.hpp"

void doCollision(PhysicsObject& obj, sf::CircleShape& shape, sf::Vector2u& winSize);


#endif // !1
