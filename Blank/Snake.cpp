#include "Snake.h"

Segment::Segment(int i_x, int i_y)
{
    x = i_x * 52 + 5;
    y = i_y * 52 + 5;
    this->block = sf::RectangleShape(sf::Vector2f(40, 40));
    this->block.setPosition(sf::Vector2f(this->x, this->y));
    this->block.setFillColor(sf::Color::White);
    this->moveDirection = Directions::Right;
}

Segment::Segment(int i_x, int i_y, sf::Color col)
{
    x = i_x * 52 + 5;
    y = i_y * 52 + 5;
    this->block = sf::RectangleShape(sf::Vector2f(40, 40));
    this->block.setPosition(sf::Vector2f(this->x, this->y));
    this->block.setFillColor(col);
    this->moveDirection = Directions::Right;
}

void Segment::draw(sf::RenderWindow &window)
{
    window.draw(this->block);
}

Directions Segment::getDirection()
{
    return this->moveDirection;
}

void Segment::setDirection(Directions newDirection)
{
    if (((int)this->getDirection() - (int)newDirection) != 2) {
        this->moveDirection = newDirection;
    }
}

void Segment::move()
{
    switch (this->moveDirection)
    {
    case Directions::Down:
        this->y += 52;
        break;
    case Directions::Up:
        this->y -= 52;
        break;
    case Directions::Left:
        this->x -= 52;
        break;
    case Directions::Right:
        this->x += 52;
        break;
    default:
        break;
    }
    this->block.setPosition(sf::Vector2f(this->x, this->y));
}

Snake::Snake()
{
    this->body.push_back(new Segment(4, 4, sf::Color::Red));
}

void Snake::move()
{
    Directions prevDirection = this->body[0]->getDirection();
    Directions tempDirection;
    for (auto seg : this->body)
    {
        tempDirection = seg->getDirection();
        seg->setDirection(prevDirection);
        seg->move();
        prevDirection = tempDirection;
    }
}

void Snake::changeDirection(Directions newDirection)
{
    this->body[0]->setDirection(newDirection);
}

void Snake::draw(sf::RenderWindow &window)
{
    for (auto seg : this->body)
    {
        this->move();
        seg->draw(window);
    }
}
