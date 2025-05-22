#include <iostream>

class A
{
public:
   A()
   {
      std::cout << "A\n";
   }

   A(int i)
   {
      std::cout << "X\n" << i;
   }
};

class B
{
public:
   B() : m_a1(), m_a2(2)
   {
      std::cout << "B\n";
   }
   ~B()
   {
      std::cout << "D\n";
   }

private:
   A m_a1;
   A m_a2;
};

int main()
{
   std::cout << "--- this is line 36" << std::endl;
   {
      std::cout << "--- this is line 38" << std::endl;
      B test;
      std::cout << "--- this is line 40" << std::endl;
   }
   B main;
   std::cout << "--- this is line 43" << std::endl;
   return 0;
}

// Frage: Was ist der Output dieses Programms?
