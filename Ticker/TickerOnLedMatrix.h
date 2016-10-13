#include "LedMatrix.h"

enum SCROLL_SPEED
{
    SCROLL_SPEED_NONE   = 0,
    SCROLL_SPEED_SLOW   = 500,
    SCROLL_SPEED_MEDIUM = 300,
    SCROLL_SPEED_FAST   = 200
};

class Ticker
{
public:
    Ticker();
   ~Ticker();
   void draw();
   void tick();
   void loadImage(byte [][8]);
private:
    LedMatrix *_ledMatrix;
    byte       _image[][8];
};