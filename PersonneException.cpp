//
// Created by Duroy on 06/01/2021.
//

#include "PersonneException.h"

PersonneException::PersonneException(const std::string &arg) : runtime_error(arg) {}

PersonneAbsentException::PersonneAbsentException(const std::string &arg) : PersonneException(arg) {}

PersonneDejaPresentException::PersonneDejaPresentException(const std::string &arg) : PersonneException(arg) {}
