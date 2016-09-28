#include "LedMatrix.h"

enum GameSpeed
{
  GAME_SPEED_NONE   = 0,
  GAME_SPEED_SLOW   = 1000,
  GAME_SPEED_MEDIUM = 700,
  GAME_SPEED_FAST   = 400   
};

enum Direction
{
  DIRECTION_NONE  =  0,
  DIRECTION_UP,
  DIRECTION_DOWN,
  DIRECTION_LEFT,
  DIRECTION_RIGHT
};

struct Point
{
  unsigned int x;
  unsigned int y;
};

class SnakeGame
{
private:
  LedMatrix  *_ledMatrix;
  Point      *_snake;
  Point      *_snakeTail;
  Point      *_snakeHead;
  Point      _target;
  Direction  _snakeDirection;
  void       _snakeChangeDir(const Direction&);
  Point      _snakeMove();
  void       _snakeOnEat();
public:
  SnakeGame(LedMatrix*);
  ~SnakeGame();
  void proceed();
};


