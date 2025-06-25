#include <iostream>
#include "tagesgeld.hpp"

Tagesgeld::Tagesgeld(int BLZ, int mindeslaufzeit)
: BankAccount(BLZ)
, m_mindeslaufzeit{mindeslaufzeit}
{
   BankAccount::m_tagesgeldCount += 1;
}

Tagesgeld::~Tagesgeld()
{
    BankAccount::m_tagesgeldCount -= 1;
}

void Tagesgeld::printSpecificInfo() const
{
   std::cout << "Mindeslaufzeit: " << m_mindeslaufzeit << std::endl;
}

void Tagesgeld::deposit(double depositValue)
{
   double newBalance = getBalance() + depositValue;
   if (newBalance < 0)
   {
      std::cout << "Current balance does not allow this withdraw." << std::endl;
   }
   else
   {
      setBalance(newBalance);
   }
}
