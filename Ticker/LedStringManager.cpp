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
    _start = nullptr;
    _end = nullptr;
}

LedStringManager::~LedStringManager()
{
    for (LedMatrixStrip **node = &_start; *node; *node = (*node)->next)
        delete *node;
}

bool LedStringManager::loadStr(const char *str)
{
    const char *currLetter = str;
    LedMatrixStrip *currNode = new LedMatrixStrip(*currLetter);
    LedMatrixStrip *lastNode = currNode;
    _start = currNode;
    currNode = currNode->next;
    
    while (*(currLetter++) != '\0')
    {
        currNode = new LedMatrixStrip(*currLetter);
        lastNode->next = currNode;

        if (currNode->image == NULL)
        {
            delete this;
            return false;
        }

        lastNode = currNode;
        currNode = currNode->next;
    }
    
    _end = currNode;

    strip = _start;

    return true;
}