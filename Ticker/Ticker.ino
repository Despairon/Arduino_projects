#include "Ticker.h"
Ticker *ticker;

void setup()
{
    pinMode(ARDUINO_LED, OUTPUT);
    digitalWrite(ARDUINO_LED,LOW);
    ticker = new Ticker();
}

void loop()
{

  

}
