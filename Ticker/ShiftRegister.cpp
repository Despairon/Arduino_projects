#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(const char &dataPin, const char &latchPin, const char &clockPin)
{
  _data = dataPin;
  _latch = latchPin;
  _clock = clockPin;

  pinMode(_data, OUTPUT);
  pinMode(_latch, OUTPUT);
  pinMode(_clock, OUTPUT);
  closeLatch();
}

ShiftRegister::~ShiftRegister() { }

void ShiftRegister::openLatch()
{
    digitalWrite(_latch, LOW);
}

void ShiftRegister::closeLatch()
{
    digitalWrite(_latch, HIGH);
}

void ShiftRegister::sendOutput(const byte &output)
{
    shiftOut(_data, _clock, LSBFIRST, output);
}
