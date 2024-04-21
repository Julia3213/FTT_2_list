#pragma once
#include <stdexcept>
#include <string>

class ListException : public std::exception {
private:
    std::string errorMessage;

public:
    ListException(const std::string& error);
    virtual const char* what() const noexcept override;
};