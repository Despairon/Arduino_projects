#include "TickerOnLedMatrix.h"
static Ticker *ticker;

void setup()
{
    pinMode(ARDUINO_LED, OUTPUT);
    digitalWrite(ARDUINO_LED,LOW);
    ticker = new Ticker();
    LedMatrixStrip *strip = new LedMatrixStrip();
    strip->image[0] = B00000000;
    strip->image[1] = B01000000;
    strip->image[2] = B01000000;
    strip->image[3] = B01000000;
    strip->image[4] = B01000000;
    strip->image[5] = B01111100;
    strip->image[6] = B00000000;
    strip->image[7] = B00000000;
    strip->next = new LedMatrixStrip();
    strip->next->image[0] = B00000000;
    strip->next->image[1] = B01000010;
    strip->next->image[2] = B01000010;
    strip->next->image[3] = B01000010;
    strip->next->image[4] = B01000010;
    strip->next->image[5] = B01111110;
    strip->next->image[6] = B00000000;
    strip->next->image[7] = B00000000;
    strip->next->next = new LedMatrixStrip();
    strip->next->next->image[0] = B00000000;
    strip->next->next->image[1] = B01000010;
    strip->next->next->image[2] = B00100100;
    strip->next->next->image[3] = B00011000;
    strip->next->next->image[4] = B00100100;
    strip->next->next->image[5] = B01000010;
    strip->next->next->image[6] = B00000000;
    strip->next->next->image[7] = B00000000;
    strip->next->next->next = new LedMatrixStrip();
    strip->next->next->next->image[0] = B00000000;
    strip->next->next->next->image[1] = B00111000;
    strip->next->next->next->image[2] = B01000100;
    strip->next->next->next->image[3] = B10000010;
    strip->next->next->next->image[4] = B10000010;
    strip->next->next->next->image[5] = B01000100;
    strip->next->next->next->image[6] = B00111000;
    strip->next->next->next->image[7] = B00000000;
    strip->next->next->next->next = new LedMatrixStrip();
    strip->next->next->next->next->image[0] = B00000000;
    strip->next->next->next->next->image[1] = B01111100;
    strip->next->next->next->next->image[2] = B01000000;
    strip->next->next->next->next->image[3] = B01110000;
    strip->next->next->next->next->image[4] = B01000000;
    strip->next->next->next->next->image[5] = B01000000;
    strip->next->next->next->next->image[6] = B00000000;
    strip->next->next->next->next->image[7] = B00000000;
    strip->next->next->next->next->next = new LedMatrixStrip();
    strip->next->next->next->next->next->image[0] = B00000000;
    strip->next->next->next->next->next->image[1] = B01111100;
    strip->next->next->next->next->next->image[2] = B00010000;
    strip->next->next->next->next->next->image[3] = B00010000;
    strip->next->next->next->next->next->image[4] = B00010000;
    strip->next->next->next->next->next->image[5] = B00010000;
    strip->next->next->next->next->next->image[6] = B00000000;
    strip->next->next->next->next->next->image[7] = B00000000;
    ticker->loadImage(strip);
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
