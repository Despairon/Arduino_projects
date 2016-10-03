#include "SnakeGame.h"

static LedMatrix *ledMatrix;
static SnakeGame *snakeGame;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
    pinMode(ARDUINO_LED, OUTPUT);
    digitalWrite(ARDUINO_LED, LOW);
    randomSeed(analogRead(0));
    ledMatrix = new LedMatrix();
    snakeGame = new SnakeGame(ledMatrix);
}

void loop() 
{
    static unsigned long dTime = 0;
    if ( (millis() - dTime) >= GAME_SPEED_MEDIUM)
    {
        snakeGame->proceed();
        dTime = millis();
    }
    ledMatrix->draw();
}
