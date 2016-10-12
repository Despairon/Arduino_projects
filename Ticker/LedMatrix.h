#include "ShiftRegister.h"
class LedMatrix
{
private:
  byte _image[8];
  ShiftRegister *columnRegister;
  ShiftRegister *rowRegister;
public: 
  LedMatrix();
 ~LedMatrix();
  void  ledOn    (const int&, const int&);
  void  ledOff   (const int&, const int&);
  void  draw();
  void  loadImage(byte[8]);
};
