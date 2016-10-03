#include "LedMatrix.h"
#define NONE NULL
#define LEFT_BORDER  1U
#define UPPER_BORDER 1U
#define RIGHT_BORDER 8U
#define LOWER_BORDER 8U

enum Direction
{
    DIRECTION_NONE = 0,
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

struct Point
{
    unsigned int x;
    unsigned int y;
};

struct SnakePart
{
    Point       coords;
    SnakePart  *nextPart;
};

class Snake
{
private:
    SnakePart  *_snakeHead;
    SnakePart  *_snakeTail;
    Direction   _dir;
public:
    Snake();
    ~Snake();
    void        eat(const Point&);
    const Point move(void(*drawFunc)(const SnakePart&, const void *const),
                     void(*eraseFunc)(const SnakePart&, const void *const),
                     const void *const);
    void        changeDir(const Direction&);
    bool        collidesWith(const Point&);
    const Point move_AI(const Point&,
                        void(*drawFunc)(const SnakePart&, const void *const),
                        void(*eraseFunc)(const SnakePart&, const void *const),
                        const void *const);
    bool        biteItself();
};