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
        Point targetLocation;
        do
        {
            targetLocation.x = random(LEFT_BORDER, RIGHT_BORDER + 1);
            targetLocation.y = random(UPPER_BORDER, LOWER_BORDER + 1);
        } while (_snake->collidesWith(targetLocation));
            *_target = targetLocation;
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

void SnakeGame::gameReboot()
{
    wdt_enable(WDTO_15MS);
    while (1) { }   
}

void SnakeGame::proceed()
{
    Point snakeHead = _snake->move_AI(*_target, &SnakeGame::_drawSnakePart, &SnakeGame::_eraseSnakePart, (const void *const)this);
    if (_snake->biteItself())
    {
        gameReboot();
    }
    if ((snakeHead.x == _target->x) && (snakeHead.y == _target->y))
    {
        _snake->eat(*_target);
        _spawnTarget();
    }
    if (_target)
        _ledMatrix->ledOn(_target->x, _target->y);
}

