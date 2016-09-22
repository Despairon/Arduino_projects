#include "Arduino.h"
#include "defines.h"
class ShiftRegister
{
private:
  char _data;
  char _latch;
  char _clock;
public:
  ShiftRegister(const char&, const char&, const char&);
  ~ShiftRegister();
  void openLatch();
  void closeLatch();
  void sendOutput(const byte&);
};
