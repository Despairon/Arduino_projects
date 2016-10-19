#include "TickerOnLedMatrix.h"

Ticker::Ticker()
{
    _ledMatrix = new LedMatrix();
}

Ticker::~Ticker() 
{
    if (_ledMatrix)
        delete _ledMatrix;
    _clearStrip();
}

void Ticker::draw()
{
    _ledMatrix->draw();
}

void Ticker::tick()
{
    static LedMatrixStrip *currStripPart = _startImage;
    static uint8_t iterator = 0;
    static byte imageToDraw[8] = 
    {
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000,
        B00000000
    };

    if (iterator > 8)
    {
        iterator = 0;
        if (currStripPart->next)
        {
            /*for (int i = 0; i < 8; i++)
                currStripPart->next->image[i] |= imageToDraw[i];*/
            currStripPart = currStripPart->next;
        }
        else
        {
            currStripPart = _startImage;
            for (int i = 0; i < 8; i++)
                imageToDraw[i] = B00000000;
        }
    }

    for (int i = 0; i < 8; i++)
        imageToDraw[i] = currStripPart->image[i] >> (7 - iterator);   
    iterator++;
    
    _ledMatrix->loadImage(imageToDraw);    
}

void Ticker::loadImage(LedMatrixStrip *startImage)
{
    _startImage = startImage;
}

void Ticker::_clearStrip()
{
    if (_startImage)
    {
        LedMatrixStrip *lastImage;
        LedMatrixStrip *currImage = _startImage;
        while (currImage)
        {
            lastImage = currImage;
            currImage = currImage->next;
            delete lastImage;
        }
        delete currImage;
    }
}