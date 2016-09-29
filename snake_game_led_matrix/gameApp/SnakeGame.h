#include "Snake.h"

enum GameSpeed
{
  GAME_SPEED_NONE   = 0,
  GAME_SPEED_SLOW   = 1000,
  GAME_SPEED_MEDIUM = 700,
  GAME_SPEED_FAST   = 400   
};

class SnakeGame
{
private:
  LedMatrix *_ledMatrix;
  Point     *_target;
  Snake     *_snake;
  void       _spawnTarget();
public:
  SnakeGame(LedMatrix*);
  ~SnakeGame();
  void proceed();
};


