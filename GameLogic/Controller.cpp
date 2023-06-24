#include "Controller.h"


void controller(sf::Event &event, sf::RenderWindow &window, Snake &snake)
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
            snake.changeDirection(Directions::Left);
        case sf::Keyboard::Up:
            snake.changeDirection(Directions::Up);
        case sf::Keyboard::Down:
            snake.changeDirection(Directions::Down);
        case sf::Keyboard::Right:
            snake.changeDirection(Directions::Right);
        }
    }
}