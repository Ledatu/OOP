#pragma once
#include "SkillFactory.h"
#include "DoubleDamage.h"

class DoubleDamageFactory : public SkillFactory
{
public:
    Skill *make(SkillInfoHolder *skillInfoHolder) override;
    std::string name() override;
};