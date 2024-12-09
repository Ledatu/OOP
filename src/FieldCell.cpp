#include "FieldCell.h"

FieldCell::FieldCell() : state(unknown), shipCell(nullptr) {}

FieldCellState FieldCell::getState()
{
    return state;
};

void FieldCell::setState(FieldCellState fieldCellState)
{
    this->state = fieldCellState;
};

bool FieldCell::attack(unsigned damage = 1)
{
    if (state == unknown)
    {
        if (shipCell != nullptr)
        {
            state = hasShip;
        }
        else
        {
            state = empty;
        }
    }

    if (state == hasShip)
    {
        return shipCell->takeDamage(damage);
    }
}

void FieldCell::setShipCell(ShipCell &shipCell)
{
    this->shipCell = &shipCell;
}

bool FieldCell::isShip() { return shipCell != nullptr; }

std::ostream &operator<<(std::ostream &os, FieldCell &cell)
{
    os << (cell.state != unknown || true ? (cell.isShip() ? (cell.shipCell->getState() == intact ? "2" : (cell.shipCell->getState() == damaged ? "1" : "0")) : ".") : "_");
    return os;
}
