#pragma once
#include "LedMatrix.h"
#include "ASCII_8x8_BitMap.h"

struct LedMatrixStrip
{
    byte image[8];
    LedMatrixStrip *next;

    LedMatrixStrip(const uint8_t&);
    LedMatrixStrip(byte []);
    ~LedMatrixStrip();
};
