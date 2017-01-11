#include "TickerOnLedMatrix.h"

Ticker::Ticker(const char *str)
{
    _ledMatrix = new LedMatrix();
    _strMgr = new LedStringManager();
    strcpy(_savedSequence, str);
    _strMgr->loadStr(str);
    _startImage = _strMgr->strip;
}

Ticker::~Ticker()
{
    if (_ledMatrix)
        delete _ledMatrix;
    if (_strMgr)
        delete _strMgr;
}

void Ticker::draw()
{
    _ledMatrix->draw();
}

void Ticker::tick()
{
    static LedMatrixStrip *currImage = _startImage;
    static uint8_t rowsPassed = 0;
    static byte imageToDraw[8] = { 0 };

    if (rowsPassed > 8)
    {
        rowsPassed = 0;
        if (currImage->next)
            currImage = currImage->next;
        else
        {
            _reset();
            currImage = _startImage;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        imageToDraw[i] = (imageToDraw[i] << 1) | (currImage->image[i] >> 7);
        currImage->image[i] = currImage->image[i] << 1;
    }
    
    rowsPassed++;

}

void Ticker::_reset()
{
    _strMgr->loadStr(_savedSequence);
    _startImage = _strMgr->strip;
}