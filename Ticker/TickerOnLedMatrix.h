#include "LedMatrix.h"

struct LedMatrixStrip
{
    byte image[8];
    LedMatrixStrip *next;
};

enum SCROLL_SPEED
{
    SCROLL_SPEED_SLOW   = 190,
    SCROLL_SPEED_MEDIUM = 140,
    SCROLL_SPEED_FAST   = 70
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
    void            _copyImage(LedMatrixStrip*, LedMatrixStrip*);
    bool            _isImageLoaded;
};