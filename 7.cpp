#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Color random_color()
{
    sf::Color randomColor(std::rand() % 256, std::rand() % 256, std::rand() % 256);
    return randomColor;
}

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::RectangleShape rect(sf::Vector2f(200.f, 100.f));
    rect.setPosition(sf::Vector2f(40.f, 40.f));

    //Random colors
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //Variables
    //Speed of moving rect
    float Xspeed = 3;
    float Yspeed = 3;
    float Aspeed = 0.3;

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Update

        //Rotate
        rect.rotate(Aspeed);

        //Colisions
        sf::FloatRect bounds = rect.getGlobalBounds();
        sf::Vector2f pos = bounds.getPosition();
        sf::Vector2f size = bounds.getSize();
        sf::Vector2u window_size = window.getSize();
        //Bottom
        if (pos.y + size.y >= window_size.y)
        {
            Yspeed = abs(Yspeed) * -1;
            rect.setFillColor(random_color());
        }
        //Top
        if (pos.y <= 0.f)
        {
            Yspeed = abs(Yspeed);
            rect.setFillColor(random_color());
        }
        //Right
        if (pos.x + size.x >= window_size.x)
        {
            Xspeed = abs(Yspeed) * -1;
            rect.setFillColor(random_color());
        }
        //Left
        if (pos.x <= 0.f)
        {
            Xspeed = abs(Xspeed);
            rect.setFillColor(random_color());
        }

        //Hitbox
        sf::RectangleShape hitbox(sf::Vector2f(0, 0));
        hitbox.setOutlineThickness(3);
        hitbox.setFillColor(sf::Color::Transparent);
        hitbox.setOutlineColor(sf::Color::White);

        //Move
        rect.move(sf::Vector2f(Xspeed, Yspeed));

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        //Show rect hitbox
        //hitbox.setPosition(pos);
        //hitbox.setSize(size);
        //window.draw(hitbox);

        window.draw(rect);

        // end the current frame
        window.display();
    }

    return 0;
}