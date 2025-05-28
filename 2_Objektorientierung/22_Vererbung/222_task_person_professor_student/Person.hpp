#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
public:
    Person(std::string name, std::string address, std::string email);
    ~Person();

    std::string getName();

protected:
    std::string m_name;
    std::string m_address;
    std::string m_email;
};

#endif // !PERSON_HPP