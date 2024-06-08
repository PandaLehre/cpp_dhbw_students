#include "class.hpp"



Class::Class()
{
}
Class::~Class()
{
}

int Class::getStaticValue()
{
   return m_staticValue;
}

int Class::getNumberOfObjects()
{
   return m_ClassCounter;
}