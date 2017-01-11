#include "LedStringManager.h"
#include "ASCII_8x8_BitMap.h"

LedMatrixStrip::LedMatrixStrip(const uint8_t &letter)
{
    int letter_index;
    if ((letter >= 'a') && (letter <= 'z'))
        letter_index = (letter - 'a') + 1;
    else if (letter == ' ')
        letter_index = 0;
    else return;
    memcpy(image, eng_alphabet_map[letter_index].image, sizeof(image));
}

LedMatrixStrip::LedMatrixStrip(byte image[])
{
    memcpy(this->image, image, sizeof(this->image));
}

LedMatrixStrip::~LedMatrixStrip() {}

LedStringManager::LedStringManager()
{
    _start       = nullptr;
    _end         = nullptr;
    _start->next = _end;
    _end->next   = nullptr;
    strip = _start;
}

LedStringManager::~LedStringManager()
{
    for (_start; _start != _end; _start++)
        delete _start;
}

bool LedStringManager::loadStr(const char *str)
{
    const char *currLetter = str;
    const LedMatrixStrip *currNode = _start;
    
    while (currLetter++)
    {
        if (currNode)
        {
            delete currNode;
            currNode = nullptr;
        }

        currNode = new LedMatrixStrip(*currLetter);
        if (currNode->image == NULL)
        {   
            delete this;
            return false;
        }
        currNode = currNode->next;
    }
    
    return true;
}