#include <SFML/Graphics.hpp>
#include "PhysicsObject.h"
#include <vector>
#include <random>
#include "updateSim.h"

int main()
{
    //////////////////////////////////////////////////////////////
    std::srand(999);

    int objectCount{25};
    const float CIRCLE_RADIUS{5};
    float dt{ 0.01 };

    std::vector<PhysicsObject> objectVector{};

    for (int i = 0; i < objectCount; i++) {
        
        Vec2D pos{static_cast<float>(std::rand() % 1101), static_cast<float>(std::rand() % 700) };
        Vec2D lastPos{ static_cast<float>(std::rand() % 1101), static_cast<float>(std::rand() % 700) };
        Vec2D acceleration{0, 0};

        PhysicsObject obj{ pos, lastPos, acceleration };
        
        objectVector.push_back(obj);    
    };
    
    std::vector<sf::CircleShape> shapeVector{};

    for (int i = 0; i < objectCount; i++) {
        sf::CircleShape newCircle{ CIRCLE_RADIUS, 30 };
        newCircle.setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
        newCircle.setFillColor(sf::Color::Green);

        sf::Vector2f posVec{ objectVector[i].getCurrentPosition().getX(), objectVector[i].getCurrentPosition().getY() };

        newCircle.setPosition(posVec);

        shapeVector.push_back(newCircle);
    };


    //////////////////////////////////////////////////////////////
    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");

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
        window.clear(sf::Color::Black);

        updateSim(dt, objectVector, shapeVector);

        for (int i = 0 ; i < shapeVector.size(); i++) {
            window.draw(shapeVector[i]);

            shapeVector[i].setPosition(objectVector[i].getCurrentPosition().getX(), objectVector[i].getCurrentPosition().getY());
        };

        // end the current frame
        window.display();
    }

    return 0;
}