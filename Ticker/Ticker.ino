#include "TickerOnLedMatrix.h"
static Ticker *ticker;

void setup()
{
    pinMode(ARDUINO_LED, OUTPUT);
    digitalWrite(ARDUINO_LED,LOW);
    ticker = new Ticker();
}

void loop()
{
    static unsigned long dTime = 0;
    if ((millis() - dTime) > SCROLL_SPEED_MEDIUM)
    {
        ticker->tick();
        dTime = millis();
    }
    ticker->draw();
}
