#include "SnakeGame.h"

#define NONE NULL
#define START_POS_X 1U
#define START_POS_Y 1U

SnakeGame::SnakeGame(LedMatrix *ledMatrix)
{
  this->_ledMatrix = ledMatrix;
  _snake = new Point[2];
  _snake[0].x = START_POS_X;
  _snake[0].y = START_POS_Y;
  _snake[1].x = START_POS_X + (unsigned int)DIRECTION_RIGHT;
  _snake[1].y = START_POS_Y;
}

SnakeGame::~SnakeGame()
{
  if (_snake)
    delete _snake;
}

void SnakeGame::_snakeChangeDir(const Direction &newDirection)
{
  _snakeDirection = newDirection;  
}

Point SnakeGame::_snakeMove()
{
  Point pt;
  return pt;
}

void SnakeGame::_snakeOnEat()
{
  
}

void SnakeGame::proceed()
{
  
}

