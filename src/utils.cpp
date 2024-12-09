#include <cstdlib>
#include "utils.h"

int clamp(int val, int lbd, int rbd)
{
    if (val < lbd)
        val = lbd;
    else if (val > rbd)
        val = rbd;
    return val;
}

int randomInt(int min, int max)
{
    int range = max - min + 1;
    return std::rand() % range + min;
}

Position::Position() : xVal(0), yVal(0) {}
Position::Position(int x, int y) : xVal(x), yVal(y) {}
void Position::set(int x, int y)
{
    xVal = x;
    yVal = y;
}

int Position::x() { return xVal; }
int Position::y() { return yVal; }

std::istream &operator>>(std::istream &is, Position &position)
{
    int x = 0;
    int y = 0;

    if (!(is >> x >> y))
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::runtime_error("Некорректный ввод координат.");
    }

    position.set(x, y);
    return is;
}

Direction::Direction() : direction(Directions::North) {}
Direction::Direction(Directions direction) : direction(direction) {}
void Direction::set(Directions direction)
{
    this->direction = direction;
}

Directions Direction::get() { return direction; }

std::istream &operator>>(std::istream &is, Direction &direction)
{
    char ch = '\0';
    std::cout << "Введите направление: (w|n|e|s)\n";
    if (!(is >> ch))
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Некорректный ввод направления.");
    }

    switch (ch)
    {
    case 'w':
        direction.set(Directions::West);
        break;
    case 's':
        direction.set(Directions::South);
        break;
    case 'e':
        direction.set(Directions::East);
        break;
    case 'n':
        direction.set(Directions::North);
        break;
    default:
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Вы ввели некорректное направление.");
    }

    return is;
}

UserInput::UserInput() : userInput(UserInputs::Attack) {}
UserInput::UserInput(UserInputs userInput) : userInput(userInput) {}
void UserInput::set(UserInputs userInput)
{
    this->userInput = userInput;
}

UserInputs UserInput::get() { return userInput; }

std::istream &operator>>(std::istream &is, UserInput &userInput)
{
    char ch = '\0';
    std::cout << "Выберите действие:\n\ta - атаковать\n\tu - использовать скилл\n\ts - сохранить игру\n\tl - загрузить игру\n";
    if (!(is >> ch))
    {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Некорректный ввод действия.");
    }

    switch (ch)
    {
    case 'a':
        userInput.set(UserInputs::Attack);
        break;
    case 'u':
        userInput.set(UserInputs::UseSkill);
        break;
    case 's':
        userInput.set(UserInputs::SaveGame);
        break;
    case 'l':
        userInput.set(UserInputs::LoadGame);
        break;
    default:
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Некорректный ввод действия.");
    }

    return is;
}