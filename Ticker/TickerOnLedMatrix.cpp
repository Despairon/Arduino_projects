#include "TickerOnLedMatrix.h"

Ticker::Ticker()
{
    _ledMatrix = new LedMatrix();
}

Ticker::~Ticker() 
{
    if (_ledMatrix)
        delete _ledMatrix;
    if (_image)
        delete[] _image;
}

void Ticker::draw()
{
    _ledMatrix->draw();
}

void Ticker::tick()
{

}

void Ticker::loadImage(byte image[][8])
{

}