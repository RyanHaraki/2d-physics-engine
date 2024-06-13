class Renderer
{
public:
    Renderer(sf::RenderTarget &target) : m_target(target) {}

    void render(const BodyManager &bodyManager, sf::RenderWindow &window)
    {

        printf("Test");
        // render all objects
        sf::CircleShape circle{1.0f};
        circle.setPointCount(32);
        circle.setOrigin(1.0f, 1.0f);
        const auto &objects = const_cast<BodyManager &>(bodyManager).getBodies();
        for (const auto &object : objects)
        {
            circle.setRadius(object->radius);
            circle.setPosition(object->position);
            window.draw(circle);
        }
    }

private:
    sf::RenderTarget &m_target;
};
