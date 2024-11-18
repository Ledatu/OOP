#include "ShellingFactory.h"

Skill *ShellingFactory::make(SkillInfoHolder *skillInfoHolder)
{
    return new Shelling(skillInfoHolder->getShipManager());
}

std::string ShellingFactory::name()
{
    return "Shelling";
}