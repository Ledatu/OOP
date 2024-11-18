#pragma once
#include "ShipCell.h"
#include <vector>

class ShipCell;

class Ship
{
private:
    std::vector<ShipCell> ship;

public:
    Ship(unsigned length);

    unsigned getLength();
    ShipCell &at(unsigned index);
    bool isDead();
};
