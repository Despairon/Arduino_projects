#include "Snake.h"

Snake::Snake()
{
    _snakeTail = new SnakePart;
    _snakeTail->coords.x = LEFT_BORDER;
    _snakeTail->coords.y = UPPER_BORDER;
    _snakeHead = new SnakePart;
    _snakeHead->coords.x = LEFT_BORDER + 1;
    _snakeHead->coords.y = UPPER_BORDER;
    _snakeTail->nextPart = _snakeHead;
    _dir = Direction::DIRECTION_RIGHT;
}

Snake::~Snake()
{
    for (SnakePart **currPart = &_snakeTail; currPart <= &_snakeHead; currPart++)
        if (*currPart)
            delete (*currPart);
}

void Snake::changeDir(const Direction &newDir)
{
    _dir = newDir;
}

const Point Snake::move(void(*drawFunc)(const SnakePart&, const void *const),
                        void(*eraseFunc)(const SnakePart&, const void *const),
                        const void *const gameObj)
{
    (*eraseFunc)(*_snakeTail, gameObj);
    SnakePart *currPart = _snakeTail;
    while (currPart != _snakeHead)
    {
        currPart->coords = currPart->nextPart->coords;
        (*drawFunc)(*currPart, gameObj);
        currPart = currPart->nextPart;
    }
    switch (_dir)
    {
    case DIRECTION_UP:
        _snakeHead->coords.y--;
        if ((_snakeHead->coords.y) < UPPER_BORDER)
            _snakeHead->coords.y = LOWER_BORDER;
        break;
    case DIRECTION_RIGHT:
        _snakeHead->coords.x++;
        if ((_snakeHead->coords.x) > RIGHT_BORDER)
            _snakeHead->coords.x = LEFT_BORDER;
        break;
    case DIRECTION_DOWN:
        _snakeHead->coords.y++;
        if ((_snakeHead->coords.y) > LOWER_BORDER)
            _snakeHead->coords.y = UPPER_BORDER;
        break;
    case DIRECTION_LEFT:
        _snakeHead->coords.x--;
        if ((_snakeHead->coords.x) < LEFT_BORDER)
            _snakeHead->coords.x = RIGHT_BORDER;
        break;
    default:
        break;
    }
    (*drawFunc)(*_snakeHead, gameObj);
    return _snakeHead->coords;
}

void Snake::eat(const Point &target)
{
    /*unsigned int oldHeadX = _snakeHead->coords.x;
    unsigned int oldHeadY = _snakeHead->coords.y;
    SnakePart *currPart = _snakeTail;
    while (currPart < _snakeHead)
        currPart++;
    _snakeHead->nextPart = new SnakePart;
    _snakeHead = _snakeHead->nextPart;
    _snakeHead->coords.x = target.x;
    _snakeHead->coords.y = target.y;
    currPart->nextPart->coords.x = oldHeadX;
    currPart->nextPart->coords.y = oldHeadY;*/
}

bool Snake::collidesWith(const Point &point)
{
    for (SnakePart *currPart = _snakeTail; currPart <= _snakeHead; currPart++)
        if (currPart->coords.x == point.x && currPart->coords.y == point.y)
            return true;
    return false;
}