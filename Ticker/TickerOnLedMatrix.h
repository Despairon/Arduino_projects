#include "LedStringManager.h"

enum SCROLL_SPEED
{
    SCROLL_SPEED_SLOW   = 190,
    SCROLL_SPEED_MEDIUM = 140,
    SCROLL_SPEED_FAST   = 70
};

class Ticker
{
public:
    Ticker(const char*);
   ~Ticker();
   void draw();
   void tick();
private:
    LedMatrix        *_ledMatrix;
    LedMatrixStrip   *_startImage;
    LedStringManager *_strMgr;
    char             *_savedSequence;
    void              _reset();
};