#include "DoubleDamageFactory.h"

Skill *DoubleDamageFactory::make(SkillInfoHolder *skillInfoHolder)
{
    return new DoubleDamage(skillInfoHolder->getField());
}

std::string DoubleDamageFactory::name()
{
    return "DoubleDamage";
}
