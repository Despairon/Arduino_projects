#include "TickerOnLedMatrix.h"

static Ticker *ticker;

void setup()
{
    Serial.begin(9600);

    pinMode(ARDUINO_LED, OUTPUT);
    digitalWrite(ARDUINO_LED,LOW);
    ticker = new Ticker("luxoft ");
}

void loop()
{
    static unsigned long dTime = 0;

    if ((millis() - dTime) > SCROLL_SPEED_FAST)
    {
        ticker->tick();
        dTime = millis();
    }

    ticker->draw();
}
