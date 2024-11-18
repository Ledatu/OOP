#include "NoSkillsAvailable.h"

NoSkillsAvailable::NoSkillsAvailable()
{
    message = "Нет доступных скиллов";
}

const char *NoSkillsAvailable::what() const noexcept
{
    return message.c_str();
}
