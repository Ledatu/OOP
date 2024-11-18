#pragma once
#include "SkillFactory.h"
#include "Scaner.h"

class ScanerFactory : public SkillFactory
{
public:
    Skill *make(SkillInfoHolder *skillInfoHolder) override;
    std::string name() override;
};