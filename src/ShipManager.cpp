#include "ShipManager.h"

ShipManager::ShipManager(std::vector<unsigned> lengths)
{
    for (auto &length : lengths)
    {
        ships.push_back(new Ship(length));
    }
}

Ship &ShipManager::at(unsigned index)
{
    return *ships.at(index);
}

unsigned ShipManager::getLength()
{
    return ships.size();
}