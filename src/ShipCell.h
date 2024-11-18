#pragma once
#include <iostream>
#include "Ship.h"

class Ship;

enum ShipCellState
{
    destroyed,
    damaged,
    intact
};

class ShipCell
{
private:
    ShipCellState state;
    Ship *ship;

public:
    ShipCell(Ship *ship);

    ShipCellState getState();
    void setState(ShipCellState);
    bool takeDamage(unsigned);
    bool isShipDead();
};
