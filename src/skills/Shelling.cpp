#include "Shelling.h"

Shelling::Shelling(ShipManager &shipManager) : shipManager(&shipManager) {}

bool Shelling::use()
{
    std::vector<ShipCell *> shipCells;
    for (int i = 0; i < shipManager->getLength(); i++)
    {
        auto &ship = shipManager->at(i);
        for (int j = 0; j < ship.getLength(); j++)
        {
            if (ship.isDead())
                continue;

            shipCells.push_back(&ship.at(j));
        }
    }

    while (shipCells.size())
    {
        int index = (std::rand() % shipCells.size());

        if (shipCells[index]->getState() != destroyed)
        {
            bool isDead = shipCells[index]->takeDamage(1);
            return isDead;
        }
    }

    return false;
}