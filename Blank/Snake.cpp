#include "Snake.h"


Segment::Segment(int i_x, int i_y, Directions direct, sf::Color col)
{
    pos = Position(i_x, i_y);
    this->block = sf::RectangleShape(sf::Vector2f(40, 40));
    this->block.setPosition(sf::Vector2f(i_x * 52 + 5, i_y * 52 + 5));
    this->block.setFillColor(col);
    this->moveDirection = direct;
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
        pos.y += 1;
        break;
    case Directions::Up:
        pos.y -= 1;
        break;
    case Directions::Left:
        pos.x -= 1;
        break;
    case Directions::Right:
        pos.x += 1;
        break;
    default:
        break;
    }
    this->block.setPosition(sf::Vector2f(pos.x * 52 + 5, pos.y * 52 + 5));
}

Position Segment::getPosition() {
    return pos;
}

void Segment::setPosition(Position newPos)
{
    pos = newPos;
    this->block.setPosition(sf::Vector2f(pos.x * 52 + 5, pos.y * 52 + 5));
}

Snake::Snake()
{
    this->body.push_back(new Segment(4, 4, Directions::Right, sf::Color::Red));
}

void Snake::increaseBody()
{
    body.push_back(new Segment(lastPos.x, lastPos.y, body.back()->getDirection()));
}

void Snake::move()
{
    Position prevPosition = this->body[0]->getPosition();
    Position tempPosition;
    this->body[0]->move();
    for (size_t i = 1; i < this->body.size(); i++)
    {
        tempPosition = this->body[i]->getPosition();
        this->body[i]->setPosition(prevPosition);
        prevPosition = tempPosition;
        lastPos = this->body[i]->getPosition();
    }
}

void Snake::changeDirection(Directions newDirection)
{
    this->body[0]->setDirection(newDirection);
}

void Snake::draw(sf::RenderWindow &window)
{
    move();
    for (auto seg : this->body)
    {
        seg->draw(window);
    }
}

bool Snake::posInSnake(Position& pos, bool withHead)
{
    for (size_t i = (withHead ? 0 : 1); i < body.size(); i++) {
        if (pos == body[i]->getPosition()) {
            return true;
        }
    }
    return false;
}

Position Snake::getHeadPos()
{
    return body[0]->getPosition();
}
