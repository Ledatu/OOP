#pragma once
#include "InfoHolder.h"
#include "../Field.h"
#include "../ShipManager.h"
#include "../utils.h"
#include <optional>

class Field;
class Shipmanager;

class SkillInfoHolder : public InfoHolder
{
    Field *field;
    ShipManager *shipManager;
    Position position;

public:
    SkillInfoHolder(std::optional<Field *> field = std::nullopt, std::optional<ShipManager *> shipManager = std::nullopt, std::optional<Position *> position = std::nullopt);
    ~SkillInfoHolder();
    void read() override {};
    ShipManager &getShipManager();
    Field &getField();
    Position &getPosition();
    void setShipManager(ShipManager &shipManager);
    void setField(Field &field);
    void setPosition(Position &position);
};
