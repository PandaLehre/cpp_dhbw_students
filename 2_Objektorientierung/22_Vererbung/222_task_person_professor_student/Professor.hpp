#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Person.hpp"
#include <string>

class Professor : public Person
{
public:
    Professor(std::string name, std::string address, std::string email);
private:
    std::string m_iban;
};

#endif // !PROFESSOR_HPP