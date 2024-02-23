#include <SFML/Graphics.hpp>

// position = pos_last + velocity * deltaTime

class Rigidbody
{
public:
    sf::Vector2f position;      // position of x, y coordinates
    sf::Vector2f position_last; // position of x, y coordinates
    sf::Vector2f acceleration;  // acceleration of x, y coordinates (change in speed and direction)
    sf::CircleShape shape;      // shape of object
    float radius = 10.0f;       // radius of object
    float mass = 1.0f;          // mass of object

    // CONSTRUCTORS --------------------------------------------------------------------------------

    // rigidbody with default position (0, 0) and radius
    Rigidbody()
    {
        position = sf::Vector2f(0, 0);
        position_last = sf::Vector2f(0, 0);
        shape = sf::CircleShape(10);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        radius = 10;
        mass = 1;
    };

    // Rigidbody with position (x, y), radius
    Rigidbody(float x, float y, float r, float m)
    {
        position = sf::Vector2f(x, y);
        position_last = sf::Vector2f(x, y);
        shape = sf::CircleShape(r);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
        radius = r;
        mass = m;
    }

    // METHODS --------------------------------------------------------------------------------

    // update the position of the object
    void update(float deltaTime)
    {
        manageConstraints();
        applyForce(sf::Vector2f(0, 9.8 * mass)); // gravity
        const sf::Vector2f velocity = position - position_last;
        position_last = position;
        position += velocity + acceleration * (deltaTime * deltaTime);
        shape.setPosition(position);
    }

    // apply a force to the object
    void applyForce(sf::Vector2f force)
    {
        acceleration += force;
    }

    void manageConstraints()
    {
        if (position.y > 900)
        {
            position.y = 900;
            acceleration.y = 0;
        }

        if (position.x > 900)
        {
            position.x = 900;
            acceleration.x = 0;
        }
    }
};

class BodyManager
{
public:
    std::vector<std::unique_ptr<Rigidbody>> bodies;

    // Add a Rigidbody and return a pointer for direct manipulation
    Rigidbody *addBodyAndGetPtr(std::unique_ptr<Rigidbody> rb)
    {
        Rigidbody *ptr = rb.get();
        bodies.push_back(std::move(rb));
        return ptr;
    }

    void updateBodies(float deltaTime)
    {
        for (auto &rb : bodies)
        {
            rb->update(deltaTime);
        }
    }

    const std::vector<std::unique_ptr<Rigidbody>> &getBodies() const
    {
        return bodies;
    }
};
