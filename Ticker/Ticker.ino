#include "TickerOnLedMatrix.h"
static Ticker *ticker;

void setup()
{
    pinMode(ARDUINO_LED, OUTPUT);
    digitalWrite(ARDUINO_LED,LOW);
    ticker = new Ticker();
    LedMatrixStrip *strip = new LedMatrixStrip();
    strip->image[0] = B11000000;
    strip->image[1] = B11000000;
    strip->image[2] = B11000000;
    strip->image[3] = B11000000;
    strip->image[4] = B11000000;
    strip->image[5] = B11000000;
    strip->image[6] = B11111111;
    strip->image[7] = B11111111;
    /*strip->next = new LedMatrixStrip();
    strip->next->image[0] = B00000000;
    strip->next->image[1] = B00000000;
    strip->next->image[2] = B00000000;
    strip->next->image[3] = B00000000;
    strip->next->image[4] = B00000000;
    strip->next->image[5] = B00000000;
    strip->next->image[6] = B00000000;
    strip->next->image[7] = B00000000;*/
    ticker->loadImage(strip);
}

void loop()
{
    static unsigned long dTime = 0;
    if ((millis() - dTime) > SCROLL_SPEED_SLOW)
    {
        ticker->tick();
        dTime = millis();
    }
    ticker->draw();
}
