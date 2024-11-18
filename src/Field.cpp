#include "Field.h"
#include "utils.h"

Field::Field(unsigned width, unsigned height)
    : width(width), height(height), field(height, std::vector<FieldCell>(width)), useDoubleDamageFlag(false) {}

Field::Field(const Field &other)
    : width(other.width), height(other.height), field(other.field) {}

Field::Field(Field &&other) noexcept
    : width(other.width), height(other.height), field(std::move(other.field))
{
    other.width = 0;
    other.height = 0;
}

Field &Field::operator=(const Field &other)
{
    if (this == &other)
    {
        return *this;
    }
    width = other.width;
    height = other.height;
    field = other.field;
    return *this;
}

Field &Field::operator=(Field &&other) noexcept
{
    if (this == &other)
    {
        return *this; // Handle self-assignment
    }
    width = other.width;
    height = other.height;
    field = std::move(other.field);
    other.width = 0;
    other.height = 0;
    return *this;
}

bool Field::attack(unsigned x, unsigned y, unsigned damage = 1)
{
    if (useDoubleDamageFlag)
    {
        damage = 2;
        useDoubleDamageFlag = false;
    }
    return getCell(x, y).attack(damage);
}

bool Field::addShip(unsigned x, unsigned y, Directions direction, Ship &ship)
{
    int length = ship.getLength();

    int boundingBoxX1 = x - 1;
    int boundingBoxX2 = x + 1;
    int boundingBoxY1 = y - 1;
    int boundingBoxY2 = y + 1;

    switch (direction)
    {
    case West:
        boundingBoxX1 -= length - 1;
        break;

    case North:
        boundingBoxY1 -= length - 1;
        break;

    case East:
        boundingBoxX2 += length - 1;
        break;

    case South:
        boundingBoxY2 += length - 1;
        break;
    }

    for (int i = clamp(boundingBoxY1, 0, height - 1); i <= clamp(boundingBoxY2, 0, height - 1); i++)
    {
        for (int j = clamp(boundingBoxX1, 0, width - 1); j <= clamp(boundingBoxX2, 0, width - 1); j++)
        {
            if (field[i][j].isShip())
            {
                throw ShipNear();
            }
        }
    }

    boundingBoxX1 += 1;
    boundingBoxX2 -= 1;
    boundingBoxY1 += 1;
    boundingBoxY2 -= 1;

    if (boundingBoxX1 < 0 || boundingBoxX2 >= width || boundingBoxY1 < 0 || boundingBoxY2 >= height)
    {
        throw NotInField();
    }

    // std::cout << "boundingBox: " << "(" << boundingBoxX1 << ", " << boundingBoxY1 << ") (" << boundingBoxX2 << ", " << boundingBoxY2 << ")\n";

    int shipIndex = 0;
    for (int i = boundingBoxY1; i <= boundingBoxY2; i++)
    {
        for (int j = boundingBoxX1; j <= boundingBoxX2; j++)
        {
            ShipCell &shipsell = ship.at(shipIndex);
            field[i][j].setShipCell(shipsell);
            shipIndex++;
        }
    }

    return true;
}

unsigned Field::getHeight()
{
    return height;
}

unsigned Field::getWidth()
{
    return width;
}

std::ostream &operator<<(std::ostream &os, Field &field)
{
    for (int i = 0; i < field.getHeight(); i++)
    {
        for (int j = 0; j < field.getWidth(); j++)
        {
            os << field.field[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

bool Field::checkCell(int x, int y)
{
    if (x < 0 || x >= getWidth())
        throw NotInField();
    if (y < 0 || y >= getHeight())
        throw NotInField();

    return true;
}

FieldCell &Field::getCell(int x, int y)
{
    checkCell(x, y);
    return field[y][x];
}

void Field::useDoubleDamage()
{
    useDoubleDamageFlag = true;
}