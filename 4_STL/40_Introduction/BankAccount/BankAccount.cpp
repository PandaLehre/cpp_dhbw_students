//
// Created by andre on 06.06.2024.
//

#include "BankAccount.h"
#include <random>
#include <iostream>

#include <chrono>
#include <algorithm>


//TODO Ausgabe, Zinsenberechnen
BankAccount::BankAccount() {
    int newIBAN = 0;
    do {
        std::random_device device;
        std::mt19937 generator(device());
        std::uniform_int_distribution<int> dist(100000, 999999);
        newIBAN = dist(generator);
    } while (IBANGen::isUsed(newIBAN) && newIBAN > 100000 && newIBAN < 999999);
    //} while (IBANGen::isUsedSTL(newIBAN) && newIBAN > 100000 && newIBAN < 999999);

    this->IBAN = newIBAN;
    IBANGen::add(newIBAN);
    //IBANGen::addSTL(newIBAN);
}

bool BankAccount::isOverdrawn() const {
    return overdrawn;
}

void BankAccount::in(double amount) {
    this->moneyMoneyCash += fabs(amount);
}

void BankAccount::out(double amount) {
    amount = fabs(amount);
    if (amount > moneyMoneyCash)this->overdrawn = true;
    this->moneyMoneyCash -= amount;
}

int BankAccount::getIban() const {
    return IBAN;
}

double BankAccount::getMoneyMoneyCash() const {
    return moneyMoneyCash;
}

double BankAccount::getIdleMoneyMakingFactor() const {
    return idleMoneyMakingFactor;
}

int BankAccount::getBlz() const {
    return BLZ;
}





std::vector<int> IBANGen::usedVectors = std::vector<int>();

//search for used IBAN using binary search
bool IBANGen::isUsed(int IBAN) {
    int low = 0, high = (int)IBANGen::usedVectors.size();
    int mid = (low + high) / 2;
    while (low <= high && !IBANGen::usedVectors.empty()) {
        if (IBAN < usedVectors[mid]) {
            high = --mid;
        } else if (IBAN > usedVectors[mid]) {
            low = ++mid;
        } else if (IBAN == usedVectors[mid]) {
            return true;
        }
        mid = (low + high) / 2;
    }
    return false;
}

void bubbleSort(std::vector<int> &v, int start, int end) {
    bool swapped = true;
    for (int i = start; i < end && swapped; ++i) {
        swapped = false;
        for (int j = start; j < end-1-i; ++j) {
            if (v[j+1] < v[j]) {
                std::swap(v[j],v[j+1]);
                swapped = true;
            }
        }
    }
}

//add iban to used vectors and sort it --> required for bubble sort
void IBANGen::add(int IBAN) {
    IBANGen::usedVectors.push_back(IBAN);
    bubbleSort(IBANGen::usedVectors, 0, IBANGen::usedVectors.size());
}

void IBANGen::addSTL(int IBAN) {
    IBANGen::usedVectors.push_back(IBAN);
    std::sort(IBANGen::usedVectors.begin(), IBANGen::usedVectors.end());
}

bool IBANGen::isUsedSTL(int IBAN) {
    return std::find(IBANGen::usedVectors.begin(), IBANGen::usedVectors.end(), IBAN) != IBANGen::usedVectors.end();
}





int main() {
    BankAccount account1;
    BankAccount account2;
    BankAccount account3;
    
    for (int & iban : IBANGen::usedVectors) {
        std::cout << "Iban: " << iban << std::endl;
    }


    auto start_time = std::chrono::steady_clock::now();
    std::vector<int> ibanList(5000);
    for (unsigned int i = 0; i < 5000; i++) {
        BankAccount account_tmp;
        ibanList[i] = account_tmp.getIban();
    }
    auto end_time = std::chrono::steady_clock::now();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Time to get 5000 IBANS: " << milliseconds << std::endl;


    

    return 0;
}

