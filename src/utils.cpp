#include <cstdlib>
#include "utils.h"

int clamp(int val, int lbd, int rbd)
{
    if (val < lbd)
        val = lbd;
    else if (val > rbd)
        val = rbd;
    return val;
}

int randomInt(int min, int max)
{
    int range = max - min + 1;
    return std::rand() % range + min;
}

Position::Position() : xVal(0), yVal(0) {}
Position::Position(int x, int y) : xVal(x), yVal(y) {}
void Position::set(int x, int y)
{
    xVal = x;
    yVal = y;
}

int Position::x() { return xVal; }
int Position::y() { return yVal; }
