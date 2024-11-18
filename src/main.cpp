#include <iostream>
#include <vector>
#include "Field.h"
#include "ShipManager.h"
#include "utils.h"
#include "skills/SkillManager.h"
#include "exceptions/NoSkillsAvailable.h"
#include "exceptions/ShipNear.h"
#include "exceptions/NotInField.h"
#include "infoHolders/SkillInfoHolder.h"

int main()
{
    auto field = Field(10, 10);
    std::cout << "\n";
    std::cout << field;
    std::cout << "\n";

    std::vector<unsigned> lengths;
    // for (unsigned i = 1; i <= 4; i++)
    // {
    //     for (unsigned j = 1; j <= 4 - i + 1; j++)
    //     {
    //         lengths.push_back(i);
    //         // std::cout << i << " ";
    //     }
    // }
    // std::cout << "\n";

    // auto shipManager = ShipManager(lengths);
    auto shipManager = ShipManager({3, 4});

    try
    {
        field.addShip(5, 3, West, shipManager.at(0));
        field.addShip(2, 8, North, shipManager.at(1));
    }
    catch (ShipNear &e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        field.attack(-100, 100, 1);
    }
    catch (NotInField &e)
    {
        std::cout << e.what() << '\n';
    }

    field.attack(3, 3, 1);
    field.attack(4, 3, 2);
    field.attack(4, 4, 2);

    std::cout << "\n";
    std::cout << field;
    std::cout << "\n";

    Position position(3, 2);
    auto skillInfoHolder = SkillInfoHolder(&field, &shipManager, &position);
    auto skillManager = SkillManager(std::vector<SkillFactory *>());
    std::cout << skillManager << '\n';

    try
    {
        std::cout << "Пробуем взять скилл когда их нет.\n";
        skillManager.getSkill(skillInfoHolder);
    }
    catch (NoSkillsAvailable &e)
    {
        std::cout << e.what() << '\n';
    }

    // // Shelling test
    // skillManager.addSkillFactory(new ShellingFactory);
    // skillManager.addSkillIfNeccessary(true);
    // auto skill = skillManager.getSkill(skillInfoHolder);
    // skillManager.addSkillIfNeccessary(skill->use());
    // free(skill);

    // // DoubleDamage test
    // skillManager.addSkillFactory(new DoubleDamageFactory);
    // skillManager.addSkillIfNeccessary(true);
    // auto skill = skillManager.getSkill(skillInfoHolder);
    // skill->use();
    // free(skill);
    // std::cout << "\n";
    // skillManager.addSkillIfNeccessary(field.attack(5, 3, 2));
    // std::cout << skillManager;
    // skillManager.addSkillIfNeccessary(field.attack(3, 3, 2));
    // std::cout << skillManager;

    // // Scaner test
    // skillManager.addSkillFactory(new ScanerFactory);
    // skillManager.addSkillIfNeccessary(true);
    // auto skill = skillManager.getSkill(skillInfoHolder);
    // std::cout << (skill->use() ? "Обнаружен корабль." : "Кораблей нет.");
    // free(skill);

    std::cout << "\n";
    std::cout << field;
    std::cout << "\n";
}
