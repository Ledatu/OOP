#pragma once

#include "../ShipManager.h"
#include "../Field.h"
#include "../skills/SkillManager.h"

#include "../libs/json.hpp"
#include <string.h>

class Serialization
{
private:
    nlohmann::json &j;

public:
    Serialization(nlohmann::json &j) : j(j) {};

    void stringify(ShipManager &shipManager, std::string key);
    void stringify(Field &field, std::string key);
    void stringify(SkillManager &abilityManager, std::string key);
};