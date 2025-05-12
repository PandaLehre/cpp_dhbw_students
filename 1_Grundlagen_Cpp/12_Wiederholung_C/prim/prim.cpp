#include <iostream>
#include <math.h>

bool checkPrime(int n)
{
   bool isPrime = true;

   for (int i = 2; i < sqrt(n) + 1; i++)
   {
      if (n % i == 0)
      {
         isPrime = false;
         break;
      }
   }

   return isPrime;
}

int main()
{
   int n = 0;
   std::cout << "--- Enter a number n: ";
   std::cin >> n;

   bool isPrime = checkPrime(n);

   std::cout << isPrime << " means: " << std::boolalpha << isPrime << std::endl;

   return 0;
}
