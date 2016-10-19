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
    strip->next = new LedMatrixStrip();
    strip->next->image[0] = B11000011;
    strip->next->image[1] = B11000011;
    strip->next->image[2] = B11000011;
    strip->next->image[3] = B11000011;
    strip->next->image[4] = B11000011;
    strip->next->image[5] = B11000011;
    strip->next->image[6] = B11111111;
    strip->next->image[7] = B11111111;
    strip->next->next = new LedMatrixStrip();
    strip->next->next->image[0] = B11000001;
    strip->next->next->image[1] = B01100011;
    strip->next->next->image[2] = B00110110;
    strip->next->next->image[3] = B00011100;
    strip->next->next->image[4] = B00011100;
    strip->next->next->image[5] = B00110110;
    strip->next->next->image[6] = B01100011;
    strip->next->next->image[7] = B11000001;
    strip->next->next->next = new LedMatrixStrip();
    strip->next->next->next->image[0] = B11111111;
    strip->next->next->next->image[1] = B11111111;
    strip->next->next->next->image[2] = B11000011;
    strip->next->next->next->image[3] = B11000011;
    strip->next->next->next->image[4] = B11000011;
    strip->next->next->next->image[5] = B11000011;
    strip->next->next->next->image[6] = B11111111;
    strip->next->next->next->image[7] = B11111111;
    strip->next->next->next->next = new LedMatrixStrip();
    strip->next->next->next->next->image[0] = B11111111;
    strip->next->next->next->next->image[1] = B11111111;
    strip->next->next->next->next->image[2] = B11000000;
    strip->next->next->next->next->image[3] = B11111000;
    strip->next->next->next->next->image[4] = B11111000;
    strip->next->next->next->next->image[5] = B11000000;
    strip->next->next->next->next->image[6] = B11000000;
    strip->next->next->next->next->image[7] = B11000000;
    strip->next->next->next->next->next = new LedMatrixStrip();
    strip->next->next->next->next->next->image[0] = B11111111;
    strip->next->next->next->next->next->image[1] = B11111111;
    strip->next->next->next->next->next->image[2] = B00011000;
    strip->next->next->next->next->next->image[3] = B00011000;
    strip->next->next->next->next->next->image[4] = B00011000;
    strip->next->next->next->next->next->image[5] = B00011000;
    strip->next->next->next->next->next->image[6] = B00011000;
    strip->next->next->next->next->next->image[7] = B00011000;
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
