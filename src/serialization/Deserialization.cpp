#include "Deserialization.h"

void Deserialization::parse(ShipManager &shipManager, std::string key)
{
    const auto &jsm = j.at(key);
    std::vector<unsigned> shipLengths;

    for (const auto &jship : jsm)
    {
        auto length = jship.at("length");
        shipLengths.push_back(length);
    }
    shipManager = ShipManager(shipLengths);

    for (size_t i = 0; i < shipManager.getLength(); i++)
    {
        std::string key = "ship_" + std::to_string(i);
        Ship &ship = shipManager.at(i);
        auto segments = jsm.at(key).at("cells");
        auto x = jsm.at(key).at("x");
        auto y = jsm.at(key).at("y");
        auto direction = jsm.at(key).at("direction");
        std::cout << "parsed position for i: " << i << " (" << x << ", " << y << ")\n";
        ship.setPosition(Position(x, y));
        ship.setDirection(Directions(direction));
        int j = 0;
        for (auto it = segments.begin(); it != segments.end(); it++)
        {
            auto segmentJson = it.value();
            ShipCellState shipCellState = segmentJson.at("state");
            ship.at(j).setState(shipCellState);
            j++;
        }
    }
    std::cout << "ended parse json for shipmanager\n";
}

void Deserialization::parse(Field &field, std::string key)
{
    const auto &JSON = j.at(key);
    field = Field(JSON.at("width"), JSON.at("height"));

    for (int y = 0; y < field.getHeight(); y++)
    {
        for (int x = 0; x < field.getWidth(); x++)
        {
            std::string key = "cell_" + std::to_string(x) + "_" + std::to_string(y);
            FieldCell &cell = field.getCell(x, y);
            cell.setState(FieldCellState(JSON.at(key).at("state")));
        }
    }
    std::cout << "ended for field\n";
}

void Deserialization::parse(SkillManager &skillManager, std::string key)
{
    const auto &jam = j.at(key);
    skillManager = SkillManager();
    skillManager.clear();
    std::cout << "ya tut";
    for (const auto &jability : jam.at("skills"))
    {
        if (jability == "DoubleDamage")
        {
            skillManager.push_back(new DoubleDamageFactory());
        }
        else if (jability == "Scaner")
        {
            skillManager.push_back(new ScanerFactory());
        }
        else if (jability == "Shelling")
        {
            skillManager.push_back(new ShellingFactory());
        }
    }
    std::cout << "Ended parse json for skillManager";
}