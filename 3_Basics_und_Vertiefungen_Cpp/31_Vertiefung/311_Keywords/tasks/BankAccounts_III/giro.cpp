#include "giro.hpp"

Giro::Giro(int BLZ) : BankAccount(BLZ) // Konstruktor Definition: Initialisierung über den Basis-Klassen-Konstruktor
{
   BankAccount::m_giroCount += 1;
}

Giro::~Giro() // Destruktor Definition
{
    BankAccount::m_giroCount -= 1;
}

void Giro::deposit(double depositValue)
{
   setBalance(getBalance() + depositValue);
   // setBalance-Methode kann über die Basisklasse aufgerufen werden (vererbt)
}

