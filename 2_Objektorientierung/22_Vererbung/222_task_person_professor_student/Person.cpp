#include "Person.hpp"
#include <iostream>

Person::Person(std::string name, std::string address, std::string email)
    : m_name(name), m_address(address), m_email(email)
{
    std::cout << "Person constructor called for " << m_name << std::endl;
}

Person::~Person() {}

std::string Person::getName()
{
    return m_name;
}
