#include <iostream>

int main()
{
   for (float x = 0.0; x != x + 1; x += 100)
   {
      std::cout << x << std::endl;
   }
}
