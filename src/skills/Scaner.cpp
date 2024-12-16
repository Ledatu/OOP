#include "Scaner.h"

Scaner::Scaner(Field &field, int x, int y) : field(&field), x(x), y(y) {}

bool Scaner::use()
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            int clampedY = clamp(y + i, 0, field->getHeight() - 1);
            int clampedX = clamp(x + j, 0, field->getWidth() - 1);
            // std::cout << clampedX << " " << clampedY << "\n";
            if (field->getCell(clampedX, clampedY).isShip())
                return true;
        }

    return false;
}
