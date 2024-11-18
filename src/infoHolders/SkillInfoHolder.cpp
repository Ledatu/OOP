#include "SkillInfoHolder.h"

SkillInfoHolder::SkillInfoHolder(std::optional<Field *> field, std::optional<ShipManager *> shipManager, std::optional<Position *> position)
{
    if (field == std::nullopt)
    {
        this->field = nullptr;
    }
    else
    {
        this->field = field.value();
    }
    if (shipManager == std::nullopt)
    {
        this->shipManager = nullptr;
    }
    else
    {
        this->shipManager = shipManager.value();
    }
    if (position == std::nullopt)
    {
        this->position = Position{0, 0};
    }
    else
    {
        this->position = *position.value();
    }
}

Field &SkillInfoHolder::getField()
{
    return *(this->field);
}

ShipManager &SkillInfoHolder::getShipManager()
{
    return *(this->shipManager);
}

Position &SkillInfoHolder::getPosition()
{
    return this->position;
}

void SkillInfoHolder::setField(Field &field)
{
    this->field = &field;
}

void SkillInfoHolder::setShipManager(ShipManager &shipManager)
{
    this->shipManager = &shipManager;
}

void SkillInfoHolder::setPosition(Position &position)
{
    this->position = position;
}

SkillInfoHolder::~SkillInfoHolder() {}
