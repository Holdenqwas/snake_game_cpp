#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "GameLogic/Controller.h"
#include "GameLogic/Snake.h"

int main()
{
    sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

    std::vector<sf::RectangleShape> figs;

    sf::RenderWindow window(sf::VideoMode(520, 520), "Snake");
    window.setFramerateLimit(30);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = TimePerFrame;

    Snake snake = Snake();
    while (window.isOpen())
    {
        sf::Event event;

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            while (window.pollEvent(event))
            {
                controller(event, window, snake);
            }

            for (size_t i = 1; i < 10; i++)
            {
                sf::RectangleShape line_h = sf::RectangleShape(sf::Vector2f(520, 2));
                line_h.setPosition(sf::Vector2f(0, i * 52));
                line_h.setFillColor(sf::Color::White);

                figs.push_back(line_h);
                    
                sf::RectangleShape line_v = sf::RectangleShape(sf::Vector2f(520, 2));
                line_v.setPosition(sf::Vector2f(i * 52, 0));
                line_v.rotate(90);
                line_v.setFillColor(sf::Color::White);

                figs.push_back(line_v);
            }
            window.clear(sf::Color::Black);
            for (auto item : figs)
            {
                window.draw(item);
            };

            snake.draw(window);
            window.display();
            figs.clear();

        }
    }
    return 0;
}
