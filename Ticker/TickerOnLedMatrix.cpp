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

void Ticker::_saveSequence()
{
    /*if (_startImage)
    {
        LedMatrixStrip *currImage = _startImage;
        LedMatrixStrip *currSequenceImg = _savedSequence;
        while (currImage)
        {
            currSequenceImg = new LedMatrixStrip();
            for (int i = 0; i < 8; i++)       
                currSequenceImg->image[i] = currImage->image[i];
            currImage = currImage->next;
            currSequenceImg = currSequenceImg->next;
        }
        currSequenceImg = new LedMatrixStrip();
        for (int i = 0; i < 8; i++)
            currSequenceImg->image[i] = currImage->image[i];
    }*/
}

void Ticker::_resetSequence()
{
    /*_clearStrip();
    if (_savedSequence)
    {
        LedMatrixStrip *currImage = _startImage;
        LedMatrixStrip *resetStartImage = currImage;
        LedMatrixStrip *currSequenceImg = _savedSequence;
        while (currSequenceImg)
        {
            currImage = new LedMatrixStrip();
            for (int i = 0; i < 8; i++)
                currImage->image[i] = currSequenceImg->image[i];
            currImage = currImage->next;
            currSequenceImg = currSequenceImg->next;
        }
        currImage = new LedMatrixStrip();
        for (int i = 0; i < 8; i++)
            currImage->image[i] = currSequenceImg->image[i];
       _startImage = resetStartImage;
    }*/
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
            currStripPart = currStripPart->next;
        else
            _resetSequence();
    }
     
    for (int i = 0; i < 8; i++)
    {
        imageToDraw[i] = (imageToDraw[i] << 1) | (currStripPart->image[i] >> 7);
        currStripPart->image[i] = currStripPart->image[i] << 1;
    }
    iterator++;
    
    _ledMatrix->loadImage(imageToDraw);    
}

void Ticker::loadImage(LedMatrixStrip *startImage)
{
    _startImage = startImage;
    _saveSequence();
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