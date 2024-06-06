#include <iostream>
#include <vector>
#include <string>

// Initialisierung von Strukturen
struct MyStruct
{
    int s_a;
    int s_b;
};

// Initialisierung von Klassen
class MyClass
{
public:
    MyClass() : m_a(0), m_b(0) {}             // Initialisierungsliste (empfohlen), default-Konstruktor (wenn kein anderer definiert ist)
    MyClass(int a, int b) : m_a(a), m_b(b) {} // Initialisierungsliste (empfohlen), Konstruktor mit Parametern, Überladung
    int m_a;
    int m_b;
};

int main()
{
    // Variablen
    int a = 5;   // klassische Initialisierung
    int b{5};    // Initialisierungsliste (empfohlen)
    int c = {5}; // gleichwertig zu b

    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl; // "a = 5"

    // Arrays
    int arr1[3] = {1, 2, 3}; // klassische Initialisierung
    int arr2[3]{1, 2, 3};    // Initialisierungsliste (empfohlen)

    for (int i = 0; i < 3; i++)
    {
        std::cout << "arr1[" << i << "] = " << arr1[i] << " arr2[" << i << "] = " << arr2[i] << std::endl;
    }

    // Verhindern von Narrowing
    double x = 5.3;
    int y = x; // klassische Initialisierung: Kein Fehler, obwohl Werteverlust
    int z{x};  // Initialisierungsliste: Fehler, da Werteverlust: narrowing conversion of 'x' from 'double' to 'int' inside { } [-Wnarrowing]

    std::cout << "x = " << x << std::endl;                 // "x = 5.3"
    std::cout << "y = " << y << " z = " << z << std::endl; // "y = 5 z = 5"

    // Aufruf Struktur
    MyStruct s1 = {1, 2}; // klassische Initialisierung
    MyStruct s2{1, 2};    // Initialisierungsliste (empfohlen)

    std::cout << "s1.s_a = " << s1.s_a << " s1.s_b = " << s1.s_b << std::endl; // "s1.s_a = 1 s1.s_b = 2"
    std::cout << "s2.s_a = " << s2.s_a << " s2.s_b = " << s2.s_b << std::endl; // "s2.s_a = 1 s2.s_b = 2"

    // Aufruf Klasse
    MyClass c1 = {1, 2}; // klassische Initialisierung
    MyClass c2{1, 2};    // Initialisierungsliste (empfohlen)

    std::cout << "c1.m_a = " << c1.m_a << " c1.m_b = " << c1.m_b << std::endl; // "c1.m_a = 1 c1.m_b = 2"
    std::cout << "c2.m_a = " << c2.m_a << " c2.m_b = " << c2.m_b << std::endl; // "c2.m_a = 1 c2.m_b = 2"

    // Initialisierung von Containern
    std::vector<int> v1 = {1, 2, 3}; // klassische Initialisierung
    std::vector<int> v2{1, 2, 3};    // Initialisierungsliste (empfohlen)

    for (int i = 0; i < 3; i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << " v2[" << i << "] = " << v2[i] << std::endl;
    }

    std::vector<std::string> v3 = {"a", "b", "c"}; // klassische Initialisierung
    std::vector<std::string> v4{"a", "b", "c"};    // Initialisierungsliste (empfohlen)

    for (int i = 0; i < 3; i++)
    {
        std::cout << "v3[" << i << "] = " << v3[i] << " v4[" << i << "] = " << v4[i] << std::endl;
    }

    return 0;
}

// Die List initAndPrint ist eine sicherere und oft klarere Art der Initialisierung in C++.
// Sie verhindert gefährliche Typumwandlungen (Narrowing),
// ist konsistent und für die meisten Initialisierungen vorzuziehen.