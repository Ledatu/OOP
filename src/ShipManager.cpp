#include "ShipManager.h"

ShipManager::ShipManager(std::vector<unsigned> lengths)
{
    for (auto &length : lengths)
    {
        std::cout << "create ship len " << length << '\n';
        ships.push_back(new Ship(length));
    }
}
ShipManager::ShipManager() {}

Ship &ShipManager::at(unsigned index)
{
    return *ships.at(index);
}

unsigned ShipManager::getLength()
{
    return ships.size();
}

bool ShipManager::allShipsDead()
{
    for (int i = 0; i < ships.size(); i++)
    {
        if (!ships.at(i)->isDead())
            return false;
    }
    return true;
}
