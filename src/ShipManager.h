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

    unsigned getLength();
    Ship &at(unsigned index);
};
