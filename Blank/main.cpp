#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "Controller.h"
#include "Snake.h"
#include "Game.h"

int main()
{
    sf::Time TimePerFrame = sf::seconds(1.f / 2.f);

    std::vector<sf::RectangleShape> figs;

    sf::RenderWindow window(sf::VideoMode(520, 520), "Snake");
    window.setFramerateLimit(30);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = TimePerFrame;
    int x = 50, y = 50;

    Snake snake = Snake();
    Game game = Game();

    for (int i = 1; i < 10; i++)
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

            window.clear(sf::Color::Black);
            for (auto item : figs)
            {
                window.draw(item);
            };

            game.checkStatus(snake, window);
            game.draw(window);

            snake.draw(window);

            window.display();
        }
    }
    return 0;
}
