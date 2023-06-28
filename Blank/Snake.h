#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "utils.h"

class Segment
{
public:
    Segment(){};
    Segment(int x, int y);
    Segment(int x, int y, sf::Color col);
    ~Segment(){};
    Directions getDirection();
    void setDirection(Directions newDirection);
    void move();
    void draw(sf::RenderWindow &window);
    Directions moveDirection;
private:
    int x;
    int y;
    
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

private:
    std::vector<Segment*> body;
};
