#include "ShipNear.h"

ShipNear::ShipNear()
{
    message = "Рядом другой корабль";
}

const char *ShipNear::what() const noexcept
{
    return message.c_str();
}