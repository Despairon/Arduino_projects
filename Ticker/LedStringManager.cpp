#include "LedStringManager.h"

LedMatrixStrip::LedMatrixStrip(const uint8_t &letter)
{
    if (((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z')) || (letter == ' '))
        memcpy(image, eng_alphabet_map[letter].image, sizeof(image));
}

LedMatrixStrip::LedMatrixStrip(byte image[])
{
    memcpy(this->image, image, sizeof(this->image));
}

LedMatrixStrip::~LedMatrixStrip() {}