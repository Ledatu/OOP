#pragma once

#include "../ShipManager.h"
#include "../Field.h"
#include "../skills/SkillManager.h"

#include <string.h>
#include "../libs/json.hpp"

class Deserialization
{
private:
    nlohmann::json &j;

public:
    Deserialization(nlohmann::json &j) : j(j) {};

    void parse(ShipManager &shipManager, std::string key);
    void parse(Field &field, std::string key);
    void parse(SkillManager &abilityManager, std::string key);
};