#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Renderer.h"
#include <iostream>
#include <memory>
#include <vector>

#define dt 0.01f // delta time

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "2D Physics Engine");
    window.setFramerateLimit(60);

    BodyManager bodyManager;
    Renderer renderer(window);

    // Add a Rigidbody to the manager and get a pointer to it for direct manipulation
    Rigidbody *rbPtr = bodyManager.addBodyAndGetPtr(std::make_unique<Rigidbody>(100, 100, 10, 1));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // apply forces/setup simulation here

        bodyManager.updateBodies(dt);

        if (rbPtr->position.x <= 250)
        {
            rbPtr->applyForce(sf::Vector2f(5, 0));
        }

        cout << rbPtr->position.x << " " << rbPtr->position.y << endl;

        renderer.render(bodyManager, window);
        window.display();
    }

    return 0;
}
