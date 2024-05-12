#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include <vector>
#include <random>
#include <iostream>
#include <cmath>
#include "subVectors.h"
#include "multByScalar.h"
#include "addVectors.h"

int main()
{
    //////////////////////////////////////////////////////////////
    std::srand(9);

    int objectCount{500};
    const float CIRCLE_RADIUS{50};
    const double dt{ 0.001 };
    const float grav{ 32.2 };
    Vec2D gravity{ grav / dt, grav/dt };
    const float coeffElast{ 0.01 };
    int numSubsteps{10};

    const int WINDOW_START[2] { 400,720};
    //////////////////////////////////////////////////////////////


   std::vector<PhysicsObject> objectVector{};


  for (int i = 0; i < objectCount; i++) {
        
        Vec2D pos{static_cast<float>(std::rand() % WINDOW_START[0]),static_cast<float>(std::rand() % WINDOW_START[1])};

        for (int j = 0; j < objectVector.size(); j++) {
            if ((pos.getX() == objectVector[j].getCurrentPosition().getX())) {
                Vec2D pos{ static_cast<float>(std::rand() % WINDOW_START[0]),static_cast<float>(std::rand() % WINDOW_START[1]) };
            };
        };

        Vec2D lastPos{ pos.getX(), pos.getY()};
        Vec2D acceleration{0, 0};

        PhysicsObject obj{ pos, lastPos, acceleration , static_cast<float>(std::rand() % 10)};

        //PhysicsObject obj{ pos, lastPos, acceleration , 5 };
        
        objectVector.push_back(obj);    
    };
    
    std::vector<sf::CircleShape> shapeVector{};

    for (int i = 0; i < objectCount; i++) {
        sf::CircleShape newCircle{ objectVector[i].getRadius(), 100 };
        newCircle.setOrigin(objectVector[i].getRadius(), objectVector[i].getRadius());
        //newCircle.setFillColor(sf::Color::Color(floor(std::rand() % 255), floor(std::rand() % 255), floor(std::rand() % 255)));
        newCircle.setFillColor(sf::Color::White);
        sf::Vector2f posVec{ objectVector[i].getCurrentPosition().getX(), objectVector[i].getCurrentPosition().getY() };

        newCircle.setPosition(posVec);

        shapeVector.push_back(newCircle);
    };

    //shapeVector[0].setFillColor(sf::Color::Yellow);

    //////////////////////////////////////////////////////////////
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_START[0], WINDOW_START[1]), "My window");
    //window.setFramerateLimit(30);
    sf::Clock clock;

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
        //window.clear(sf::Color::Color(26, 176, 184));

        window.clear(sf::Color::Black);

        for (int i = 0; i < objectVector.size(); i++) {
            PhysicsObject& physObj{ objectVector[i] };

            //physObj.accelerate(gravity);

            for (int substep = 0; substep < numSubsteps; ++substep) {
                physObj.accelerate(gravity);
                physObj.updateSubstep(dt / numSubsteps, 1);
                physObj.applyConstraints(window.getSize(), physObj.getRadius());
                physObj.doCollisions(objectVector, coeffElast, window.getSize());

            //std::cout << physObj.getCurrentPosition().getX() << ", " << physObj.getCurrentPosition().getY() << std::endl;
            }
        }
        sf::Time elapsed = clock.restart();
        std::cout << 1/elapsed.asSeconds() << std::endl;

        for (int i = 0 ; i < shapeVector.size(); i++) {

            //Vec2D velocityObj{ subVectors(objectVector[i].getCurrentPosition(), objectVector[i].getAcceleration()) };

            //int velRel{ static_cast<int>(floor(velocityObj.magnitude() * velocityObj.magnitude() )) };

            //std::cout << velRel << std::endl;

            shapeVector[i].setPosition(objectVector[i].getCurrentPosition().getX(), objectVector[i].getCurrentPosition().getY());
            //shapeVector[i].setFillColor(sf::Color::Color(velRel % 255, velRel % 255, 0));
            window.draw(shapeVector[i]);
        };
        


        // end the current frame
        
       window.display();


    }

    return 0;
}