#include <iostream>
#include "bausparvertrag.hpp"

Bausparvertrag::Bausparvertrag(int BLZ, double bausparsumme)
: BankAccount(BLZ)
, m_bausparsumme(bausparsumme)
{
   BankAccount::m_bausparvertragCount += 1;
}

Bausparvertrag::~Bausparvertrag()
{
    BankAccount::m_bausparvertragCount -= 1;
}

void Bausparvertrag::deposit(const double depositValue)
{
   if (depositValue < 0)
   {
      std::cout << "Money cannot be withdrawn." << std::endl;
      return;
   }

   double newBalance = getBalance() + depositValue;
   if (newBalance >= m_bausparsumme)
   {
      std::cout << "You have reached the Bausparsumme." << std::endl;
      setBalance(m_bausparsumme);
      std::cout << newBalance - m_bausparsumme << " will not be deposited." << std::endl;
   }
   else
   {
      setBalance(newBalance);
   }
}

void Bausparvertrag::printSpecificInfo() const
{
   std::cout << "Bausparsumme: " << m_bausparsumme << std::endl;
}
