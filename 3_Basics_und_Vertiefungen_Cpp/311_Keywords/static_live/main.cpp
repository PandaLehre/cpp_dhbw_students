#include "class.hpp"
#include <iostream>

int main()
{
   int result = 0;

   // Accessing members through instance of class (old)
   Class helperClass{Class()};
   result = helperClass.m_staticValue;
   result = helperClass.getStaticValue();



   return 0;
}