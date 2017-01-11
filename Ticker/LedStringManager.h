#pragma once
#include "LedMatrix.h"

struct LedMatrixStrip
{
    byte image[8];
    LedMatrixStrip *next;

    LedMatrixStrip(const uint8_t&);
    LedMatrixStrip(byte []);
    ~LedMatrixStrip();
};

class LedStringManager
{
private:
    LedMatrixStrip *_start;
    LedMatrixStrip *_end;
public:
    LedStringManager();
   ~LedStringManager();
   bool loadStr(const char*);
   LedMatrixStrip *strip;
};
