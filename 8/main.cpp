#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "CustomRectangleShape.h"

void clicked(std::vector<CustomRectangleShape>& shapes, sf::Vector2i& mouse_pos, std::string button)
{
    for (auto& rec : shapes)
    {
        if (rec.getGlobalBounds().contains(sf::Vector2f(mouse_pos)))
        {
            if (button == "left") rec.select();
            if (button == "right") rec.unselect();
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML - Zad8");
    window.setFramerateLimit(60);

    std::vector<CustomRectangleShape> shapes;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        sf::Vector2f position(rand() % (window.getSize().x - 120), rand() % (window.getSize().y - 60));
        CustomRectangleShape rectangle(sf::Vector2f(120.0, 60.0), position);
        rectangle.setRotation(rand() % 180);
        shapes.emplace_back(rectangle);
    }

    bool up = 0;
    bool down = 0;
    bool right = 0;
    bool left = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up) up = 1;
                if (event.key.code == sf::Keyboard::Down) down = 1;
                if (event.key.code == sf::Keyboard::Right) right = 1;
                if (event.key.code == sf::Keyboard::Left) left = 1;
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up) up = 0;
                if (event.key.code == sf::Keyboard::Down) down = 0;
                if (event.key.code == sf::Keyboard::Right) right = 0;
                if (event.key.code == sf::Keyboard::Left) left = 0;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                if (event.mouseButton.button == sf::Mouse::Left) clicked(shapes, mouse_position, "left");
                if (event.mouseButton.button == sf::Mouse::Right) clicked(shapes, mouse_position, "right");
            }
        }

        for (auto& rect : shapes)
        {
            rect.animate(up, down, right, left);
        }

        window.clear();

        for (auto& rect : shapes)
        {
            window.draw(rect);
        }

        window.display();
    }

    return 0;
}