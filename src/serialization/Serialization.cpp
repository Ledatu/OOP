#include "Serialization.h"
#include <fstream>

void Serialization::stringify(ShipManager &shipManager, std::string key)
{
    nlohmann::json JSON = nlohmann::json{};

    for (int i = 0; i < shipManager.getLength(); i++)
    {
        auto &ship = shipManager.at(i);
        std::string key = "ship_" + std::to_string(i);
        JSON[key] = {
            {"length", ship.getLength()},
            {"direction", ship.getDirection().get()},
            {"x", ship.getPosition().x()},
            {"y", ship.getPosition().y()},
            {"cells", nlohmann::json::array()}};

        for (int j = 0; j < ship.getLength(); j++)
        {
            auto &shipCell = ship.at(j);
            JSON[key]["cells"].push_back({{"state", shipCell.getState()}});
        }
    }

    j[key] = JSON;
}

void Serialization::stringify(Field &field, std::string key)
{
    nlohmann::json JSON = nlohmann::json{};

    JSON["width"] = field.getWidth();
    JSON["height"] = field.getHeight();

    for (int y = 0; y < field.getHeight(); y++)
    {
        for (int x = 0; x < field.getWidth(); x++)
        {
            std::string key = "cell_" + std::to_string(x) + "_" + std::to_string(y);
            JSON[key] = {
                {"x", x},
                {"y", y},
                {"state", field.getCell(x, y).getState()}};
        }
    }
    std::cout << "ended field\n";
    j[key] = JSON;
}

void Serialization::stringify(SkillManager &skillManager, std::string key)
{
    nlohmann::json JSON = nlohmann::json{};
    for (int i = 0; i < skillManager.size(); i++)
    {
        JSON["skills"].push_back(skillManager.at(i).name());
    }

    j[key] = JSON;
}