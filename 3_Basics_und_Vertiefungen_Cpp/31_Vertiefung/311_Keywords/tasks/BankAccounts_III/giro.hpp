#ifndef GIRO_HPP_INCLUDED
#define GIRO_HPP_INCLUDED

#include "bankAccount.hpp" // Include der Basisklasse, um von ihr erben zu können

class Giro : public BankAccount
{
public:
   Giro(int BLZ); // Konstruktor Deklaration

   ~Giro(); // Destruktor Deklaration

   void deposit(double depositValue) override; // Überschreiben der rein virtuellen Methode
};

#endif // !GIRO_HPP_INCLUDED