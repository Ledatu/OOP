#pragma once
#include <exception>
#include <string>

class ShipNear : public std::exception
{

    std::string message;

public:
    ShipNear();
    const char *what() const noexcept override;
};