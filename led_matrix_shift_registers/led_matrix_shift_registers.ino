const char ARDUINO_LED = 13;
const char ROW_DATA = 2;
const char ROW_LATCH = 3;
const char ROW_CLOCK = 4;
const char COL_DATA = 8;
const char COL_LATCH = 9;
const char COL_CLOCK = 10;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

ShiftRegister::~ShiftRegister()
{

}

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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
}*ledMatrix;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

LedMatrix::LedMatrix()
{
  for (int i=0; i<8; i++)
    _image[i] = B00000000;
  columnRegister = new ShiftRegister(COL_DATA,COL_LATCH,COL_CLOCK);
  rowRegister = new ShiftRegister(ROW_DATA,ROW_LATCH,ROW_CLOCK);
}

LedMatrix::~LedMatrix()
{
  delete columnRegister;
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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);
  
  ledMatrix = new LedMatrix();
  byte heart[8] = 
  {
    B11111111,
    B10000001,
    B10100101,
    B10000001,
    B10111101,
    B10100101,
    B10000001,
    B11111111,  
  };
  ledMatrix->loadImage(heart);
}

void loop() 
{
  ledMatrix->draw();
}
