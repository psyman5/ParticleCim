#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include <vector>
#include <random>
#include "updateSim.h"
#include <iostream>
#include <cmath>
#include "subVectors.h"
#include "multByScalar.h"
#include "addVectors.h"

int main()
{
    //////////////////////////////////////////////////////////////
    std::srand(9);

    int objectCount{200};
    float CIRCLE_RADIUS{7};
    float dt{ 0.01 };
    float grav{ 9.81 };
    Vec2D gravity{ 0, grav/dt };
    const float coeffElast{0.75};
    int numSubsteps{5};
/*
    Vec2D pos1{ 300, 360 };
    Vec2D lastPos1{ pos1.getX() + 1, pos1.getY() };
    Vec2D acceleration1{ 0, 0 };

    Vec2D pos2{ 600, 360 };
    Vec2D lastPos2{ pos2.getX() - 1, pos2.getY() };
    Vec2D acceleration2{ 0, 0 };

    PhysicsObject obj1{ pos1, lastPos1, acceleration1, 5};
    PhysicsObject obj2{ pos2, lastPos2, acceleration2, 5 };



    std::vector<PhysicsObject> objectVector{obj1, obj2};
*/

    std::vector<PhysicsObject> objectVector{};


  for (int i = 0; i < objectCount; i++) {
        
        Vec2D pos{static_cast<float>(std::rand() % 1100), 380 };

        for (int j = 0; j < objectVector.size(); j++) {
            if ((pos.getX() == objectVector[j].getCurrentPosition().getX())) {
                Vec2D pos{ static_cast<float>(std::rand() % 1100), 380 };
            };
        };

        Vec2D lastPos{ pos.getX(), pos.getY()};
        Vec2D acceleration{0, 0};

        //PhysicsObject obj{ pos, lastPos, acceleration , static_cast<float>(std::rand() % 20)};

        PhysicsObject obj{ pos, lastPos, acceleration , 5 };
        
        objectVector.push_back(obj);    
    };
    
    std::vector<sf::CircleShape> shapeVector{};

    for (int i = 0; i < objectCount; i++) {
        sf::CircleShape newCircle{ objectVector[i].getRadius(), 45 };
        newCircle.setOrigin(objectVector[i].getRadius(), objectVector[i].getRadius());
        //newCircle.setFillColor(sf::Color::Color(floor(std::rand() % 255), floor(std::rand() % 255), floor(std::rand() % 255)));
        newCircle.setFillColor(sf::Color::White);
        sf::Vector2f posVec{ objectVector[i].getCurrentPosition().getX(), objectVector[i].getCurrentPosition().getY() };

        newCircle.setPosition(posVec);

        shapeVector.push_back(newCircle);
    };

    shapeVector[0].setFillColor(sf::Color::Yellow);

    //////////////////////////////////////////////////////////////
    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
    window.setFramerateLimit(165);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Color(26, 176, 184));

        //window.clear(sf::Color::White);

        for (int i = 0; i < objectVector.size(); i++) {
            PhysicsObject& physObj{ objectVector[i] };

            physObj.accelerate(gravity);

            for (int substep = 0; substep < numSubsteps; ++substep) {
                physObj.updateSubstep(dt / numSubsteps, 1);
                physObj.applyConstraints(window.getSize(), physObj.getRadius());
                physObj.doCollisions(objectVector, coeffElast);
            }
        }

        for (int i = 0 ; i < shapeVector.size(); i++) {

            Vec2D velocityObj{ subVectors(objectVector[i].getCurrentPosition(), objectVector[i].getLastPos()) };

            int velRel{ static_cast<int>(floor(velocityObj.magnitude() * velocityObj.magnitude())) };

            std::cout << velRel << std::endl;

            shapeVector[i].setPosition(objectVector[i].getCurrentPosition().getX(), objectVector[i].getCurrentPosition().getY());
            shapeVector[i].setFillColor(sf::Color::Color(20, velRel % 255, 0));
            window.draw(shapeVector[i]);
        };

        // end the current frame
        window.display();
    }

    return 0;
}