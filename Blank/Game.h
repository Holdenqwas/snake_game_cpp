#pragma once

#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "Snake.h"


class Game {
private:
	Segment* apple;
	int score;
	void eatingApple(Snake& snake);
	void spawnApple(Snake& snake);
	void gameOver(sf::RenderWindow& window);
public:
	Game();
	~Game() {};
	void draw(sf::RenderWindow& window);
	void checkStatus(Snake& snake, sf::RenderWindow& window);
};