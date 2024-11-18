#pragma once
#include "Skill.h"
#include "../Field.h"
#include "../ShipManager.h"
#include "../infoHolders/SkillInfoHolder.h"
#include <optional>

class SkillFactory
{
public:
    virtual Skill *make(SkillInfoHolder *skillInfoHolder) = 0;
    virtual std::string name() = 0;
};