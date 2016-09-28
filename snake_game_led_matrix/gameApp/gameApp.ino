#include "SnakeGame.h"

static LedMatrix *ledMatrix;
static SnakeGame *snakeGame;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);
  
  ledMatrix = new LedMatrix();
  snakeGame = new SnakeGame(ledMatrix);
}

void loop() 
{
  snakeGame->proceed();
  ledMatrix->draw();
  delay(GAME_SPEED_SLOW);
}
