#include "Snake.h"

Segment::Segment(int i_x, int i_y) : x(i_x), y(i_y)
{
    block = sf::RectangleShape(sf::Vector2f(40, 40));
    block.setPosition(sf::Vector2f(x * 50 + 5, y * 50 + 5));
    block.setFillColor(sf::Color::White);
    moveDirection = Directions::Right;
}

Segment::Segment(int i_x, int i_y, sf::Color col) : x(i_x), y(i_y)
{
    block = sf::RectangleShape(sf::Vector2f(40, 40));
    // block.setPosition(sf::Vector2f(x * 50 + 5, y * 50 + 5));
    block.setPosition(sf::Vector2f(x, y));
    block.setFillColor(col);
    moveDirection = Directions::Right;
}

void Segment::draw(sf::RenderWindow &window)
{
    window.draw(block);
}

Directions Segment::getDirection()
{
    return moveDirection;
}

void Segment::setDirection(Directions newDirection)
{
    this->moveDirection = newDirection;
}

void Segment::move()
{
    switch (this->moveDirection)
    {
    case Directions::Down:
        this->y += 52;
    case Directions::Up:
        this->y -= 52;
    case Directions::Left:
        this->x -= 52;
    case Directions::Right:
        this->x += 52;
    }

    this->block.setPosition(sf::Vector2f(this->x, this->y));
}

Snake::Snake()
{
    body.push_back(new Segment(4*52, 4*52, sf::Color::Red));
}

void Snake::move()
{
    Directions prevDirection = body[0]->getDirection();
    Directions tempDirection;
    for (auto seg : body)
    {
        tempDirection = seg->getDirection();
        seg->setDirection(prevDirection);
        seg->move();
        prevDirection = tempDirection;
    }
}

void Snake::changeDirection(Directions newDirection)
{
    body[0]->setDirection(newDirection);
}

void Snake::draw(sf::RenderWindow &window)
{
    for (auto seg : body)
    {
        this->move();
        seg->draw(window);
    }
}
