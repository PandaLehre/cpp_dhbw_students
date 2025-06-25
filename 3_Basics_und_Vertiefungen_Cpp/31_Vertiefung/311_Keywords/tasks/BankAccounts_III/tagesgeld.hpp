#ifndef TAGESGELD_HPP_INCLUDED
#define TAGESGELD_HPP_INCLUDED

#include "bankAccount.hpp"

class Tagesgeld : public BankAccount
{
public:
   Tagesgeld(int BLZ, int mindeslaufzeit);

   ~Tagesgeld();

   void deposit(double depositValue) override;

   void printSpecificInfo() const override;

private:
   const int m_mindeslaufzeit;
};

#endif // !TAGESGELD_HPP_INCLUDED