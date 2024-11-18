#include "DoubleDamage.h"

DoubleDamage::DoubleDamage(Field &field) : field(&field) {}

bool DoubleDamage::use()
{
    field->useDoubleDamage();
    return true;
}