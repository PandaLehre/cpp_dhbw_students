#ifndef BANKACCOUNT_HPP_INCLUDED
#define BANKACCOUNT_HPP_INCLUDED

class BankAccount // Basisklassen Deklaration
{
public:
   BankAccount(const int BLZ); // Konstruktor Deklaration

   virtual ~BankAccount(); // Virtueller Destruktor Deklaration
   // - virtual: damit die abgeleiteten Klassen den Destruktor überschreiben / aufrufen können

   void printInfo() const;

   virtual void printSpecificInfo() const {}; // Virtuelle Methode mit leerer Implementierung
   // - virtuell: damit die abgeleiteten Klassen die Methode überschreiben können
   // - leere Implementierung: damit die Methode in den abgeleiteten Klassen überschrieben werden kann

   virtual void deposit(const double depositValue) = 0; // Reine virtuelle Methode (pure virtual function)
   // - rein virtuell: = 0, diese Methode wird nicht in der Basisklasse implementiert werden

   void setAccountNumber(int accountNumber);

   void setBLZ(int BLZ);

   void setBalance(double balance);

   int getAccountNumber() const;

   int getBLZ() const;

   double getBalance() const;

   static int m_giroCount;
   static int m_tagesgeldCount;
   static int m_bausparvertragCount;
   static void printAccountCounts();

private:
   // Member Variablen der Basisklasse (Reihenfolge der Initialisierung in der Initialisierungsliste beachten!)
   double m_balance;
   int m_BLZ;
   int m_accountNumber;
};

#endif // !BANKACCOUNT_HPP_INCLUDED