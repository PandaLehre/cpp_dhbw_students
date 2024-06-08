#pragma once

class Class
{
public:
   Class();
   ~Class();

   // static int m_correputedNonConstStaticValue = 0;
   int m_nonConstStaticValue;
   const int m_staticValue = 0;
   int getStaticValue();
   int getNumberOfObjects();

private:
   int m_ClassCounter;
};