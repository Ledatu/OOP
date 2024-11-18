
#pragma once
#include "SkillFactory.h"
#include "Shelling.h"

class ShellingFactory : public SkillFactory
{
public:
    Skill *make(SkillInfoHolder *skillInfoHolder) override;
    std::string name() override;
};
