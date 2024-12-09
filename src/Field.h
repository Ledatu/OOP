#pragma once
#include "FieldCell.h"
#include "Ship.h"
#include <vector>
#include <ostream>
#include "exceptions/NotInField.h"
#include "exceptions/ShipNear.h"
#include "./utils.h"

class Field
{
    friend std::ostream &operator<<(std::ostream &os, Field &field);

private:
    std::vector<std::vector<FieldCell>> field;
    unsigned width;
    unsigned height;
    bool useDoubleDamageFlag;

public:
    Field();
    Field(unsigned width, unsigned height);
    Field(const Field &other);
    Field(Field &&other) noexcept;

    Field &operator=(const Field &other);
    Field &operator=(Field &&other) noexcept;

    bool checkCell(int x, int y);
    FieldCell &getCell(int x, int y);

    ~Field() = default;

    unsigned getWidth();
    unsigned getHeight();

    bool addShip(unsigned x, unsigned y, Directions direction, Ship &ship);
    bool attack(unsigned x, unsigned y, unsigned damage = 1);

    void useDoubleDamage();
};
