#include "LedMatrix.h"
LedMatrix::LedMatrix()
{
  for (int i=0; i<8; i++)
    _image[i] = B00000000;
  columnRegister = new ShiftRegister(COL_DATA,COL_LATCH,COL_CLOCK);
  rowRegister    = new ShiftRegister(ROW_DATA,ROW_LATCH,ROW_CLOCK);
}

LedMatrix::~LedMatrix()
{
    if (columnRegister)
        delete columnRegister;
    if (rowRegister)
        delete rowRegister;
}

void LedMatrix::ledOn(const int &col, const int &row)
{
  _image[row-1] |= (B10000000 >> (col-1) );
}

void LedMatrix::ledOff(const int &col, const int &row)
{
  _image[row-1] &=  ~(B10000000 >> (col-1) );
}

void LedMatrix::draw()
{
  byte row = B10000000;
  for (int i = 0; i < 8; i++)
  {
    rowRegister->openLatch();
    columnRegister->openLatch();
    if (_image[i] != 0)
      rowRegister->sendOutput(row);
    row = row >> 1;
    columnRegister->sendOutput(~_image[i]);
    columnRegister->closeLatch();
    rowRegister->closeLatch();
  }
}

void LedMatrix::loadImage(byte image[8])
{
    for (int row = 0; row < 8; row++)
      _image[row] = image[row];
}
