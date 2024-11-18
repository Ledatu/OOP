#include "SkillManager.h"

std::ostream &operator<<(std::ostream &os, SkillManager &skillManager)
{
    auto temp = skillManager.queue;

    if (temp.empty())
        os << "Список доступных скиллов пуст :(" << "\n";

    while (!temp.empty())
    {
        auto elem = temp.front();
        os << elem->name() << "\n";
        temp.pop();
    }

    return os;
}

SkillManager::SkillManager(std::optional<std::vector<SkillFactory *>> factories)
{
    this->queue = std::queue<SkillFactory *>();
    this->factories = factories.value_or(std::vector<SkillFactory *>{new ScanerFactory, new ShellingFactory, new DoubleDamageFactory});
    auto factoriesCopy(this->factories);
    while (factoriesCopy.size())
    {
        int index = std::rand() % factoriesCopy.size();
        this->queue.push(factoriesCopy[index]);
        factoriesCopy.erase(factoriesCopy.begin() + index);
    }
}

SkillManager::~SkillManager()
{
    while (!queue.empty())
    {
        auto elem = queue.front();
        queue.pop();
        delete elem;
    }
    factories.clear();
}

Skill *SkillManager::getSkill(SkillInfoHolder &skillInfoHolder)
{
    if (this->factories.empty() || this->queue.empty())
        throw NoSkillsAvailable();

    auto skillFactory = this->queue.front();
    std::cout << "Skill: " << skillFactory->name() << '\n';
    this->queue.pop();
    return skillFactory->make(&skillInfoHolder);
}

void SkillManager::addSkillIfNeccessary(bool shipDestroyed)
{
    if (this->factories.empty())
        throw NoSkillsAvailable();

    if (shipDestroyed)
        this->queue.push(factories[std::rand() % factories.size()]);
}

void SkillManager::addSkillFactory(SkillFactory *skillFactory)
{
    factories.push_back(skillFactory);
}
