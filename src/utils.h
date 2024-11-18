#pragma once

int clamp(int val, int lbd, int rbd);
int randomInt(int min, int max);

class Position
{
    int xVal;
    int yVal;

public:
    Position();
    Position(int x, int y);
    void set(int x, int y);
    int x();
    int y();
};