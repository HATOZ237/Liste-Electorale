//
// Created by Duroy on 06/01/2021.
//

#ifndef UNTITLED4_PERSONNEEXCEPTION_H
#define UNTITLED4_PERSONNEEXCEPTION_H


#include <stdexcept>

class PersonneException : public std::runtime_error {
public:
    PersonneException(const std::string &raison) : std::runtime_error(raison) {}
};

class PersonneDejaPresenteException : public PersonneException {
public:
    PersonneDejaPresenteException(const std::string &p_raison) : PersonneException(p_raison) {}
};

class PersonneAbsenteException : public PersonneException {
public:
    PersonneAbsenteException(const std::string &p_raison) : PersonneException(p_raison) {}
};


#endif //UNTITLED4_PERSONNEEXCEPTION_H
