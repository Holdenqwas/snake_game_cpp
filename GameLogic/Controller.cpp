#include <SFML/Graphics.hpp>
#include <Snake.h>
#include <utils.h>

void Controller(sf::Event &event, sf::RenderWindow &window, Snake &snake)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    else if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
            window.close();
        case sf::Keyboard::Left:
            snake.move(Directions::Left);
        case sf::Keyboard::Up:
            snake.move(Directions::Up);
        case sf::Keyboard::Down:
            snake.move(Directions::Down);
        case sf::Keyboard::Right:
            snake.move(Directions::Right);
        }
    }
}