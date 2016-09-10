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
  /*byte heart[8] = 
  {
    B00100100,
    B01011010,
    B10000001,  
    B01000010,  
    B00100100,  
    B00011000, 
    B00000000,  
    B00000000,  
  };
  ledMatrix->loadImage(heart);*/
}

void loop() 
{
  static unsigned long tTime = 0;
  unsigned long dTime = 0;
  static const unsigned long TICK = 200;
  static unsigned int switcher = 0;
  dTime = millis() - tTime;
  if (dTime >= TICK)
  {
    switch(switcher)
    {
      case 0:
        ledMatrix->ledOff(1,1);
        ledMatrix->ledOff(2,2);
        ledMatrix->ledOff(3,3);
        ledMatrix->ledOff(4,4);
        ledMatrix->ledOff(5,5);
        ledMatrix->ledOff(6,6);
        ledMatrix->ledOff(7,7);
        ledMatrix->ledOff(8,8);
        ledMatrix->ledOn(1,1);
        switcher = 1;
        break;
      case 1:
        ledMatrix->ledOn(2,2);
        switcher = 2;
        break;
      case 2:
        ledMatrix->ledOn(3,3);
        switcher = 3;
        break;
      case 3:
        ledMatrix->ledOn(4,4);
        switcher = 4;
        break;
      case 4:
        ledMatrix->ledOn(5,5);
        switcher = 5;
        break;
      case 5:
        ledMatrix->ledOn(6,6);
        switcher = 6;
        break;
     case 6:
        ledMatrix->ledOn(7,7);
        switcher = 7;
        break;
     case 7:
        ledMatrix->ledOn(8,8);
        switcher = 0;
        break;
    }
    tTime = millis();
  }
  ledMatrix->draw();
}
