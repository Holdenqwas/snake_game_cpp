#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "utils.h"

struct Position {
    int x;
    int y;
    Position() {};
    Position(int i_x, int i_y) : x(i_x), y(i_y) {};
    bool operator==(const Position& rhs) {
        return (x == rhs.x && y == rhs.y);
    }
};

class Segment
{
public:
    Segment(){};
    Segment(int i_x, int i_y, Directions direct, sf::Color col=sf::Color::White);
    ~Segment(){};
    Directions getDirection();
    void setDirection(Directions newDirection);
    void move();
    void draw(sf::RenderWindow &window);
    Position getPosition();
    void setPosition(Position newPos);
private:
    Position pos;
    Directions moveDirection;
    sf::RectangleShape block;
};

class Snake
{
public:
    Snake();
    ~Snake(){};
    void increaseBody();
    void move();
    void changeDirection(Directions newDirection);
    void draw(sf::RenderWindow &window);
    bool posInSnake(Position& pos, bool withHead=true);
    Position getHeadPos();
private:
    Position lastPos;
    std::vector<Segment*> body;
};
