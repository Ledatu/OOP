#pragma once
#include "ShipCell.h"
#include <ostream>

enum FieldCellState
{
    unknown,
    empty,
    hasShip,
};

class FieldCell
{
    friend std::ostream &operator<<(std::ostream &os, FieldCell &cell);

private:
    FieldCellState state;
    ShipCell *shipCell;

public:
    FieldCell();

    FieldCellState getState();

    bool isShip();

    bool attack(unsigned damage);
    void setShipCell(ShipCell &shipCell);
};
