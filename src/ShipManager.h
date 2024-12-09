#pragma once
#include "Ship.h"
#include "Field.h"
#include <vector>

class ShipManager
{
private:
    std::vector<Ship *> ships;

public:
    ShipManager(std::vector<unsigned> lengths);
    ShipManager();

    unsigned getLength();
    Ship &at(unsigned index);
    bool allShipsDead();
};
