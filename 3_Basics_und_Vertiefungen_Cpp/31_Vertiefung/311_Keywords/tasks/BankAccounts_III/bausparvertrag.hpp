#ifndef BAUSPARVERTRAG_HPP_INCLUDED
#define BAUSPARVERTRAG_HPP_INCLUDED

#include "bankAccount.hpp"

class Bausparvertrag : public BankAccount
{
public:
   Bausparvertrag(int BLZ, double bausparsumme);

   ~Bausparvertrag();

   void deposit(const double depositValue) override;

   void printSpecificInfo() const;

private:
   double m_bausparsumme;
};

#endif // !BAUSPARVERTRAG_HPP_INCLUDED