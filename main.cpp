#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>


int main()
{
    sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

    std::vector<sf::RectangleShape> figs;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake");
    window.setFramerateLimit(30);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = TimePerFrame;

    while (window.isOpen())
    {
        sf::Event event;

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            while (window.pollEvent(event))
            {

            }

            for (size_t i = 1; i < 10; i++)
            {
                sf::RectangleShape line_h = sf::RectangleShape(sf::Vector2f(500, 2));
                line_h.setPosition(sf::Vector2f(0, i * 50));
                line_h.setFillColor(sf::Color::White);

                figs.push_back(line_h);
                    
                sf::RectangleShape line_v = sf::RectangleShape(sf::Vector2f(500, 2));
                line_v.setPosition(sf::Vector2f(i * 50, 0));
                line_v.rotate(90);
                line_v.setFillColor(sf::Color::White);

                figs.push_back(line_v);
            }
            window.clear(sf::Color::Black);
            for (auto item : figs)
            {
                window.draw(item);
            };
            window.display();
            figs.clear();

        }
    }
    return 0;
}
