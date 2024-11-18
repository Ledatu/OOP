#include "Ship.h"

Ship::Ship(unsigned length)
{
    for (int i = 0; i < length; i++)
    {
        ship.push_back(ShipCell(this));
    }
}

unsigned Ship::getLength()
{
    return ship.size();
}

ShipCell &Ship::at(unsigned index)
{
    return ship[index];
}

bool Ship::isDead()
{
    for (int i = 0; i < ship.size(); i++)
    {
        if (ship[i].getState() != destroyed)
            return false;
    }
    return true;
}