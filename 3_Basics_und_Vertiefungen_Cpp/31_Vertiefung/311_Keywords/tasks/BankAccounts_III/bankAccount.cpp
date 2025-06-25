#include "bankAccount.hpp"

#include <iostream>
#include <random>
#include <ctime>

int generateRandomNumber()
{
   std::random_device device;
   std::mt19937 generator(device());
   std::uniform_int_distribution<int> distribution(100000, 999999);
   int randomNumber = distribution(generator);
   return randomNumber;
} // Funktion zur Generierung einer Zufallszahl, unabhängig von der Klasse

BankAccount::BankAccount(const int BLZ)
    : m_balance{0.0}, m_BLZ{BLZ}, m_accountNumber{generateRandomNumber()}
{
} // Konstruktor mit Initialisierungsliste und Default-Werten

BankAccount::~BankAccount()
{
} // Destruktor Definition

void BankAccount::printInfo() const
{
   std::cout << "Account Number: " << m_accountNumber << std::endl;
   std::cout << "BLZ: " << m_BLZ << std::endl;
   std::cout << "Current balance: " << m_balance << std::endl;
   printSpecificInfo();
}

void BankAccount::printAccountCounts()
{
   std::cout << "Count: Giro Tagesgeld Bausparvertrag: "
             << m_giroCount << " / "
             << m_tagesgeldCount << " / "
             << m_bausparvertragCount
             << std::endl;
}

void BankAccount::setAccountNumber(int accountNumber)
{
   m_accountNumber = accountNumber;
}

void BankAccount::setBLZ(int BLZ)
{
   m_BLZ = BLZ;
}

void BankAccount::setBalance(double balance)
{
   m_balance = balance;
}

int BankAccount::getAccountNumber() const
{
   return m_accountNumber;
}

int BankAccount::getBLZ() const
{
   return m_accountNumber;
}

double BankAccount::getBalance() const
{
   return m_balance;
}

// Initialisierung der statischen Member
int BankAccount::m_giroCount = 0;
int BankAccount::m_tagesgeldCount = 0;
int BankAccount::m_bausparvertragCount = 0;
