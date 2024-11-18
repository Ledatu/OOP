#pragma once

#include <exception>
#include <string>

class NoSkillsAvailable : public std::exception
{

    std::string message;

public:
    NoSkillsAvailable();
    const char *what() const noexcept override;
};