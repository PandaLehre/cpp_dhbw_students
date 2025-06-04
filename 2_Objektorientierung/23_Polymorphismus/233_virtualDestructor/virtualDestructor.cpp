#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor Called\n";
    }
    virtual ~Base()
    {
        std::cout << "Base Destructor called\n";
    }
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        dynamicArray = new int[100000]; // Speicher auf dem Heap reservieren
        std::cout << "Derived constructor called " << dynamicArray[10] << std::endl;
    }
    ~Derived1()
    {
        std::cout << "Derived destructor called " << dynamicArray[10] << std::endl;
        delete[] dynamicArray; // Heap Speicher freigeben
    }

private:
    int *dynamicArray;
};

int main()
{
    int iterations = 100000;
    for (int i = 0; i < iterations; i++)
    {
        Base *b = new Derived1();
        delete b;
    }

    std::string input;
    std::cout << "Enter Key to finish . . .";
    std::cin >> input;
}

// Was passiert, wenn der Destruktor der Basisklasse nicht virtuell ist?
// Was passiert, wenn der Destruktor der Basisklasse virtuell ist?

// In der Standardkonfiguration wird die gebaute,
// ausführbare Datei oft outDebug.exe genannt,
// wenn Sie auf einem Windows-System arbeiten.
