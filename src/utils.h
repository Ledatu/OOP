#pragma once
#include <iostream>
#include <stdexcept>

int clamp(int val, int lbd, int rbd);
int randomInt(int min, int max);

class Position
{
    friend std::istream &operator>>(std::istream &is, Position &position);

    int xVal;
    int yVal;

public:
    Position();
    Position(int x, int y);
    void set(int x, int y);
    int x();
    int y();
};

enum Directions
{
    East,
    South,
    West,
    North,
};
class Direction
{
    friend std::istream &operator>>(std::istream &is, Direction &direction);

    Directions direction;

public:
    Direction();
    Direction(Directions direction);
    void set(Directions direction);
    Directions get();
};

enum UserInputs
{
    Attack,
    UseSkill,
    SaveGame,
    LoadGame,
};
class UserInput
{
    friend std::istream &operator>>(std::istream &is, UserInput &UserInput);

    UserInputs userInput;

public:
    UserInput();
    UserInput(UserInputs userInput);
    void set(UserInputs userInput);
    UserInputs get();
};
