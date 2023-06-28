#include "Game.h"

Game::Game() {
	std::srand(std::time(nullptr));
	Position pos = Position(std::rand() % 9, std::rand() % 9);
	Position snakePos = Position(4, 4);
	while (snakePos == pos) {
		pos = Position(std::rand() % 9, std::rand() % 9);
	}
	std::cout << pos.x << " " << pos.y << std::endl;
	apple = new Segment(pos.x, pos.y, Directions::Right, sf::Color::Green);

	score = 0;
}

void Game::draw(sf::RenderWindow& window) {
	apple->draw(window);
}

void Game::checkStatus(Snake& snake, sf::RenderWindow& window)
{
	// check collision with body
	Position posHead = snake.getHeadPos();
	if (snake.posInSnake(posHead, false)) {
		gameOver(window);
	}

	// check eating apple
	Position posApple = apple->getPosition();
	if (apple->getPosition() == posHead) {
		score++;
		snake.increaseBody();
		spawnApple(snake);
	}

	//check border
	if (posHead.x < 0 || posHead.x > 9 || posHead.y < 0 || posHead.y > 9) {
		gameOver(window);
	}
}

void Game::gameOver(sf::RenderWindow& window)
{
	std::cout << "GAME OVER! Your score:" << score << std::endl;
	window.close();
}

void Game::eatingApple(Snake& snake) {

}

void Game::spawnApple(Snake& snake)
{
	Position curPos;
	bool wrongPlace = true;
	do {
		curPos = Position(std::rand() % 9, std::rand() % 9);
		wrongPlace = snake.posInSnake(curPos);
	} while (wrongPlace);
	apple->setPosition(curPos);
}
