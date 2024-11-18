#include "ShipCell.h"

ShipCell::ShipCell(Ship *ship) : ship(ship), state(intact) {};

ShipCellState ShipCell::getState()
{
    return state;
}

void ShipCell::setState(ShipCellState state)
{
    this->state = state;
}

bool ShipCell::takeDamage(unsigned damage)
{
    if (damage <= 0)
        return false;

    if (isShipDead())
        return false;

    for (unsigned i = 0; i < damage; i++)
    {
        if (state == intact)
        {
            state = damaged;
        }
        else if (state == damaged)
        {
            state = destroyed;
            break;
        }
    }

    return isShipDead();
}

bool ShipCell::isShipDead()
{
    return ship->isDead();
}