#include "LedMatrix.h"

struct LedMatrixStrip
{
    byte image[8];
    LedMatrixStrip *next;
};

enum SCROLL_SPEED
{
    SCROLL_SPEED_SLOW   = 300,
    SCROLL_SPEED_MEDIUM = 200,
    SCROLL_SPEED_FAST   = 100
};

class Ticker
{
public:
    Ticker();
   ~Ticker();
   void draw();
   void tick();
   void loadImage(LedMatrixStrip*);
private:
    LedMatrix      *_ledMatrix;
    LedMatrixStrip *_startImage;
    LedMatrixStrip *_savedSequence;
    void            _clearStrip();
    void            _reset();
    void            _saveSequence();
    bool            _isImageLoaded;
};