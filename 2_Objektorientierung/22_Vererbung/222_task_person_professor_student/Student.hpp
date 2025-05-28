#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person
{
public:
    Student(std::string name, std::string address, std::string email);
private:
    double m_averageGrade;
};

#endif // !STUDENT_HPP