#pragma once
#include "Skill.h"
#include "../Field.h"

class Scaner : public Skill
{
    Field *field;
    int x, y;

public:
    Scaner(Field &field, int x, int y);
    bool use() override;
};