#include "NotInField.h"

NotInField::NotInField()
{
    message = "Координаты не в поле";
}

const char *NotInField::what() const noexcept
{
    return message.c_str();
}