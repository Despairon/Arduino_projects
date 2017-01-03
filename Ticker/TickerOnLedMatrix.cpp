#include "TickerOnLedMatrix.h"

Ticker::Ticker()
{
    _ledMatrix = new LedMatrix();
    _isImageLoaded = false;
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
            currStripPart = currStripPart->next;
        else
            _reset();
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
    _startImage    = new LedMatrixStrip();
    LedMatrixStrip *startNode = _startImage;
    LedMatrixStrip *node = startImage;
    
    while (node)
    {
        for (int i=0; i < 8; i++)
            _startImage->image[i] = node->image[i];

        if (node->next)
        {
            _startImage->next = new LedMatrixStrip();
            _startImage = _startImage->next;
        }

        node = node->next;
    }
    
    _startImage = startNode;
    
    if (!_isImageLoaded)
        _saveSequence();

    _isImageLoaded = true;
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

void Ticker::_reset()
{
    _clearStrip();
    loadImage(_savedSequence);
}

void Ticker::_saveSequence()
{
    
}