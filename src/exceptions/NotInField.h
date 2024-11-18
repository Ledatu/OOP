#pragma once

#include <exception>
#include <string>

class NotInField : public std::exception
{

    std::string message;

public:
    NotInField();
    const char *what() const noexcept override;
};