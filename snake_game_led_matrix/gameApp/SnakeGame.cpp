#include "SnakeGame.h"

#define NONE NULL
#define START_POS_X 1U
#define START_POS_Y 1U

SnakeGame::SnakeGame(LedMatrix *ledMatrix)
{
  this->_ledMatrix = ledMatrix;
  _snake = new Point[2];
  _snakeDirection = Direction::DIRECTION_RIGHT;
  _snake[0].x = START_POS_X;
  _snake[0].y = START_POS_Y;
  _snake[1].x = START_POS_X + 1;
  _snake[1].y = START_POS_Y;
  _snakeTail = &_snake[0];
  _snakeHead = &_snake[1];
  _target.x = NONE;
  _target.y = NONE;
}

SnakeGame::~SnakeGame()
{
  if (_snake)
    delete [] _snake;
}

void SnakeGame::_snakeChangeDir(const Direction &newDirection)
{
  _snakeDirection = newDirection;  
}

Point SnakeGame::_snakeMove()
{
  Point pt;
  switch (_snakeDirection)
  {
  case DIRECTION_UP:

      break;
  case DIRECTION_RIGHT:
      
      break;
  case DIRECTION_DOWN:

      break;
  case DIRECTION_LEFT:

      break;
  default:
      break;
  }
  return pt;
}

void SnakeGame::_snakeOnEat()
{
  
}

void SnakeGame::proceed()
{
    ledMatrix->ledOff(_snakeTail->x, _snakeTail->y);
    Point next = _snakeMove();
    if ((next.x == _target.x) && (next.y == _target.y))
        _snakeOnEat();
    for (Point *pSnakePart = _snakeTail; pSnakePart < _snakeHead; pSnakePart++)
        ledMatrix->ledOn(pSnakePart->x, pSnakePart->y);
    
}

