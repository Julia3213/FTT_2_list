
#include "ListException.h"

ListException::ListException(const std::string& error) : errorMessage(error) {}

const char* ListException::what() const noexcept {
    return errorMessage.c_str();
}