const int ARDUINO_LED = 13;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class LedMatrix
{
private:
  int **_image;
  int _columns[8] = {6, 7, 8, 9, A3, A2, A1, A0};
  int _rows[8]    = {2, 3, 4, 5, 10, 11, 12, 13};
public: 
  LedMatrix();
 ~LedMatrix();
  void  ledOn    (const int&, const int&);
  void  ledOff   (const int&, const int&);
  void  blinkingLed (const int&, const int&);
  void  draw();
  void  loadImage(int[8][8]);
}*ledMatrix;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

LedMatrix::LedMatrix()
{
  _image = new int*[8];
  for (int i=0; i<8; i++)
    _image[i] = new int[8];
  for (int i=0; i<8; i++)
  {
    pinMode(_columns[i], OUTPUT);
    pinMode(_rows[i], OUTPUT);
    for (int j=0; j<8; j++)
      _image[i][j] = 0;
  }
}

LedMatrix::~LedMatrix()
{
  for (int i=0; i < 8; i++)
    delete *_image;
  delete _image;
}

void LedMatrix::ledOn(const int &col, const int &row)
{
  _image[col][row] = 1;
}

void LedMatrix::ledOff(const int &col, const int &row)
{
  _image[col][row] = 0;
}

void LedMatrix::blinkingLed(const int &col, const int &row)
{
  ledOn(col, row);
  delay(500);
  ledOff(col, row);
  delay(500);
}

void LedMatrix::draw()
{
  for (int row = 0; row < 8; row++)
  {
    digitalWrite(_rows[row], HIGH);
    for (int col = 0; col < 8; col++)
    {
      if (_image[col][row] == 1)
        digitalWrite(_columns[col], LOW); 
      else
        digitalWrite(_columns[col], HIGH); 
    }
    digitalWrite(_rows[row], LOW);
    for (int i = 0; i < 8; i++)
      digitalWrite(_columns[i], HIGH);
  }
}

void LedMatrix::loadImage(int image[8][8])
{
    for (int row = 0; row < 8; row++)
      for (int col = 0; col < 8; col++)
        _image[col][row] = image[row][col];
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() 
{
  
  pinMode(ARDUINO_LED, OUTPUT);
  digitalWrite(ARDUINO_LED, LOW);

  ledMatrix = new LedMatrix();
}

void loop() 
{
  static int ya[8][8] = 
  {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 0, 0, 0, 
    0, 0, 1, 0, 1, 0, 0, 0, 
    0, 0, 1, 1, 1, 0, 0, 0, 
    0, 0, 0, 0, 1, 0, 0, 0, 
    0, 0, 0, 1, 1, 0, 0, 0, 
    0, 0, 1, 0, 1, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
  };
  static int n[8][8] = 
  {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
  };
  static int a[8][8] = 
  {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 0,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
  };
  static int heart[8][8] = 
  {
    0, 0, 1, 0, 0, 1, 0, 0,
    0, 1, 0, 1, 1, 0, 1, 0,
    1, 0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 1, 0, 0, 1, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
  };
  static unsigned long time = millis();
  static bool firstTime = true;
  unsigned long currTime = millis();
  if (firstTime)
  {
    ledMatrix->loadImage(ya);
    firstTime = false;
  }
  if (currTime - time > 2500)
  {
    ledMatrix->loadImage(ya);
    time = currTime;
  }
  if (currTime - time > 500)
  {
    ledMatrix->loadImage(n);
  }
  if (currTime - time > 1000)
  {
    ledMatrix->loadImage(a);
  }
  if (currTime - time > 1500)
  {
    ledMatrix->loadImage(heart);
  }
  ledMatrix->draw();
}
