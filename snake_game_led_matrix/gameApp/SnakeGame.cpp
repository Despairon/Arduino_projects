#include "SnakeGame.h"

#define NONE NULL
#define LEFT_BORDER  1U
#define UPPER_BORDER 1U
#define RIGHT_BORDER 8U
#define LOWER_BORDER 8U

SnakeGame::SnakeGame(LedMatrix *ledMatrix)
{
  this->_ledMatrix = ledMatrix;
  _snake = new Point[2];
  _snakeDirection = Direction::DIRECTION_RIGHT;
  _snake[0].x = LEFT_BORDER;
  _snake[0].y = UPPER_BORDER;
  _snake[1].x = LEFT_BORDER + 1;
  _snake[1].y = UPPER_BORDER;
  _snake[2].x = LEFT_BORDER + 2;
  _snake[2].y = UPPER_BORDER;
  _snakeTail = &_snake[0];
  _snakeHead = &_snake[2];
  //_target.x = 7;
  //_target.y = 1;
  _spawnTarget();
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
  for (Point *pSnakePart = _snakeTail; pSnakePart < _snakeHead; pSnakePart++)
  {
      pSnakePart->x = (pSnakePart + 1)->x;
      pSnakePart->y = (pSnakePart + 1)->y;
  }
  switch (_snakeDirection)
  {
  case DIRECTION_UP:
        _snakeHead->y--;
        if ((_snakeHead->y) < UPPER_BORDER)
            _snakeHead->y = LOWER_BORDER;
      break;
  case DIRECTION_RIGHT:
      _snakeHead->x++;
      if ((_snakeHead->x) > RIGHT_BORDER)
          _snakeHead->x = LEFT_BORDER;
      break;
  case DIRECTION_DOWN:
      _snakeHead->y++;
      if ((_snakeHead->y) > LOWER_BORDER)
          _snakeHead->y = UPPER_BORDER;
      break;
  case DIRECTION_LEFT:
      _snakeHead->x--;
      if ((_snakeHead->x) < LEFT_BORDER)
          _snakeHead->x = RIGHT_BORDER;
      break;
  default:
      break;
  }
  return *_snakeHead;
}

void SnakeGame::_spawnTarget()
{

}

void SnakeGame::_snakeOnEat()
{
    //_ledMatrix->ledOff(_target.x, _target.y);
    //_snakeTail = NONE;
    //_snakeHead = NONE;
    //size_t snakeSizeOld = (sizeof(_snake) / sizeof(Point));
    //Point *snakeOld = (Point*)memcpy(snakeOld,_snake,snakeSizeOld);
    //delete [] _snake;
    //_snake = new Point[snakeSizeOld + 1];
    //for (unsigned int i = 0; i < snakeSizeOld; i++)
    //    _snake[i] = snakeOld[i];
    //_snake[snakeSizeOld].x = _target.x;
    //_snake[snakeSizeOld].y = _target.y;
    //_snakeTail = &_snake[0];
    //_snakeHead = &_snake[snakeSizeOld];
    //_target.x = NONE;
    //_target.y = NONE;

    //_spawnTarget();
}

void SnakeGame::proceed()
{
    _ledMatrix->ledOff(_snakeTail->x, _snakeTail->y);
    Point next = _snakeMove();
    if ((next.x == _target.x) && (next.y == _target.y))
        _snakeOnEat();
    for (Point *pSnakePart = _snakeTail; pSnakePart <= _snakeHead; pSnakePart++)
        _ledMatrix->ledOn(pSnakePart->x, pSnakePart->y);
    if (_target.x != NONE && _target.y != NONE)
        _ledMatrix->ledOn(_target.x, _target.y);
    
}

