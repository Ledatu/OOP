#include "ScanerFactory.h"

Skill *ScanerFactory::make(SkillInfoHolder *skillInfoHolder)
{
    auto &field = skillInfoHolder->getField();
    auto &pos = skillInfoHolder->getPosition();
    return new Scaner(field, pos.x(), pos.y());
}

std::string ScanerFactory::name()
{
    return "Scaner";
}
