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
    if (_target)
    {
        delete _target;
        _target = nullptr;
    }
    if (!_target)
    {
        _target = new Point;
        if (!_snake->collidesWith(*_target))
        {
            // TODO: add spawning target at random point code
        }
        _target->x = 4;    // TODO: change this shitty hardcode
        _target->y = 4;
    }
}

void SnakeGame::_drawSnakePart(const SnakePart &part, const void *const gameObj)
{
    SnakeGame *gameObjCast = reinterpret_cast<SnakeGame*>(const_cast<void*>(gameObj));
    gameObjCast->_ledMatrix->ledOn(part.coords.x, part.coords.y);
}

void SnakeGame::_eraseSnakePart(const SnakePart &part, const void *const gameObj)
{
    SnakeGame *gameObjCast = reinterpret_cast<SnakeGame*>(const_cast<void*>(gameObj));
    gameObjCast->_ledMatrix->ledOff(part.coords.x, part.coords.y);
}

void SnakeGame::proceed()
{
    Point snakeHead = _snake->move(&SnakeGame::_drawSnakePart, &SnakeGame::_eraseSnakePart, (const void *const)this);
    if ((snakeHead.x == _target->x) && (snakeHead.y == _target->y))
    {
        _snake->eat(*_target);
        _ledMatrix->ledOff(_target->x, _target->y);
        _spawnTarget();
    }
    if (_target)
        _ledMatrix->ledOn(_target->x, _target->y);

}

