#pragma once
#include "Skill.h"
#include "../ShipManager.h"

class Shelling : public Skill
{
    ShipManager *shipManager;

public:
    Shelling(ShipManager &shipManager);
    bool use() override;
};