#pragma once
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <utils.h>


class Segment{
public:
    Segment();
    ~Segment();
    void draw();
private:
    int x;
    int y;
    size_t moveDirection;
    sf::RectangleShape block;
};


class Snake{
public:
    Snake();
    ~Snake();
    void increaseBody();
    void move(Directions);
    void draw();
private:
    std::vector <Segment> body;
};
