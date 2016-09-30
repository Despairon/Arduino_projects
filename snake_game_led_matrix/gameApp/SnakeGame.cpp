#include "SnakeGame.h"

SnakeGame::SnakeGame(LedMatrix *ledMatrix)
{
  this->_ledMatrix = ledMatrix;
  _snake = new Snake();
  _spawnTarget();
}

SnakeGame::~SnakeGame()
{
  if (_snake)
      delete _snake;
  if (_target)
      delete _target;
}

void SnakeGame::_spawnTarget()
{
    if (!_target)
    {
        _target = new Point;
        _target->x = 4;    // TODO: change this shitty hardcode
        _target->y = 4;
    }
}

void SnakeGame::proceed()
{
    _snake->move();
    /*if ((_snakeHead->x == _target.x) && (_snakeHead->y == _target.y))
        _snakeOnEat();
    else
    {
        _ledMatrix->ledOff(_snakeTail->x, _snakeTail->y);
        Point next = _snakeMove();
        for (Point *pSnakePart = _snakeTail; pSnakePart <= _snakeHead; pSnakePart++)
            _ledMatrix->ledOn(pSnakePart->x, pSnakePart->y);
        if (_target.x != NONE && _target.y != NONE)
            _ledMatrix->ledOn(_target.x, _target.y);
    }*/
}

