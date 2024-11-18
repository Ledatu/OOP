#include "Scaner.h"

Scaner::Scaner(Field &field, int x, int y) : field(&field), x(x), y(y) {}

bool Scaner::use()
{
    std::cout << "x: " << x << " y: " << y << '\n';
    if (field->getCell(x, y).isShip())
        return true;
    if (field->getCell(x + 1, y).isShip())
        return true;
    if (field->getCell(x, y + 1).isShip())
        return true;
    if (field->getCell(x + 1, y + 1).isShip())
        return true;

    return false;
}