#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <queue>
#include "ShellingFactory.h"
#include "DoubleDamageFactory.h"
#include "ScanerFactory.h"
#include "Skill.h"
#include "SkillFactory.h"
#include <ostream>
#include "../infoHolders/SkillInfoHolder.h"
#include "../exceptions/NoSkillsAvailable.h"
#include <string>

class SkillManager
{
private:
    friend std::ostream &operator<<(std::ostream &os, SkillManager &skillManager);

    std::queue<SkillFactory *> queue;
    std::vector<SkillFactory *> factories;

public:
    SkillManager(std::optional<std::vector<SkillFactory *>> factories = std::nullopt);
    void clear();
    void push_back(SkillFactory *skillFactory);

    void addSkillFactory(SkillFactory *);
    void addSkillIfNeccessary(bool shipDestroyed);
    Skill *getSkill(SkillInfoHolder &skillInfoHolder);
    int size();
    SkillFactory &at(int index);
};