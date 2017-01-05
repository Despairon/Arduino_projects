#include "TickerOnLedMatrix.h"

Ticker::Ticker()
{
    _ledMatrix = new LedMatrix();
    _isImageLoaded = false;
    _savedSequence = new LedMatrixStrip();
    _startImage = new LedMatrixStrip();
}

Ticker::~Ticker()
{
    if (_ledMatrix)
        delete _ledMatrix;
    if (_startImage)
        _clearStrip();
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

    _ledMatrix->loadImage(imageToDraw);
}

void Ticker::loadImage(LedMatrixStrip *startImage)
{
    _copyImage(startImage, _startImage);

    if (!_isImageLoaded)
        _saveSequence();
}

void Ticker::_clearStrip()
{
    if (_startImage)
    {
        LedMatrixStrip *node = _startImage;
        while(node)
        {
            delete node;
            node = node->next;
        }
    }
}

void Ticker::_reset()
{
    loadImage(_savedSequence);
}

void Ticker::_copyImage(LedMatrixStrip *source, LedMatrixStrip *destination)
{
    if (source)
    {
        LedMatrixStrip *destinationNode = destination;
        LedMatrixStrip *sourceNode = source;
        LedMatrixStrip *lastNode = destinationNode;
        while (sourceNode)
        {
            if (!destinationNode)
            {
                destinationNode = new LedMatrixStrip();
                lastNode->next = destinationNode;
            }
              
            memcpy(destinationNode->image, sourceNode->image, sizeof(sourceNode->image));

            lastNode = destinationNode;
            sourceNode = sourceNode->next;
            destinationNode = destinationNode->next;
        }
     }
}

void Ticker::_saveSequence()
{
    _copyImage(_startImage, _savedSequence);
    _isImageLoaded = true;
}