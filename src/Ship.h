#pragma once
#include "ShipCell.h"
#include <vector>
#include "./utils.h"

class ShipCell;

class Ship
{
private:
    std::vector<ShipCell> ship;
    Position position;
    Direction direction;

public:
    Ship(unsigned length);

    unsigned getLength();
    ShipCell &at(unsigned index);
    bool isDead();
    void setPosition(Position position);
    Position getPosition();
    void setDirection(Direction direction);
    Direction getDirection();
};
