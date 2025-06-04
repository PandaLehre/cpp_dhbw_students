# Grundlagen C++: Stack, Pointer und Speicherverwaltung

Dieses Beispiel demonstriert grundlegende Konzepte von Pointern, Speicheradressen und Speicherverwaltung auf dem Stack und Heap in C++. Es zeigt, wie Pointer auf Variablen und Strukturen zeigen, wie Werte verändert werden und wie dynamischer Speicher mit `malloc`/`free` und `new`/`delete` verwaltet wird.

---

## Code-Übersicht

```cpp
#include <iostream>
#include <cstdlib>

struct myStruct
{
   float value1;
   float value2;
   float value3;
   float value4;
   float value5;
};

int main()
{
   // FIRST PART //
   float number1 = 2.0f;
   float *ptrToNumber1 = &number1;
   float number2 = *ptrToNumber1;

   number1 = 7.1f;
   std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;

   number2 = 23.2f;
   std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;

   *ptrToNumber1 = 0.0f;
   std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;

   int sizeOfNumber1 = sizeof(number1);
   std::cout << "\nnumber1: " << number1 << "\n -> Size of number1: " << sizeOfNumber1 << std::endl;

   int sizeOfPointer1 = sizeof(ptrToNumber1);
   std::cout << "\nptrToNumber1: " << *ptrToNumber1 << "\n -> Size of ptrToNumber1: " << sizeOfPointer1 << std::endl;

   // SECOND PART //
   myStruct myFirstStruct{10, 20, 30, 40, 50};
   int sizeOfMyStruct = sizeof(myFirstStruct);
   std::cout << "\nmyFirstStruct: " << myFirstStruct.value1 << ", " << myFirstStruct.value2 << ", "
             << myFirstStruct.value3 << ", " << myFirstStruct.value4 << ", " << myFirstStruct.value5 << std::endl;
   std::cout << " -> Size of myFirstStruct: " << sizeOfMyStruct << std::endl;

   myStruct *ptrToMyFirstStruct = &myFirstStruct;
   std::cout << " -> Address of myFirstStruct: " << ptrToMyFirstStruct << std::endl;
   std::cout << " -> Value of myFirstStruct via pointer: " << ptrToMyFirstStruct->value1 << ", "
             << ptrToMyFirstStruct->value2 << ", " << ptrToMyFirstStruct->value3 << ", "
             << ptrToMyFirstStruct->value4 << ", " << ptrToMyFirstStruct->value5 << std::endl;
   std::cout << " -> Size of pointer to myFirstStruct: " << sizeof(ptrToMyFirstStruct) << std::endl;

   // THIRD PART //
   float *pointerHeapMalloc = (float *)malloc(sizeof(float));
   if (pointerHeapMalloc == nullptr) {
       std::cerr << "Memory allocation failed!" << std::endl;
       return 1;
   }
   std::cout << "\nAddress of pointerHeapMalloc: " << pointerHeapMalloc << std::endl;

   float *pointerHeapNew = new float;
   if (pointerHeapNew == nullptr) {
       std::cerr << "Memory allocation failed!" << std::endl;
       return 1;
   }
   std::cout << "Address of pointerHeapNew: " << pointerHeapNew << std::endl;

   *pointerHeapMalloc = 3.0;
   *pointerHeapNew = 4.0;
   std::cout << "Value of pointerHeapMalloc: " << *pointerHeapMalloc << std::endl;
   std::cout << "Value of pointerHeapNew: " << *pointerHeapNew << std::endl;

   free(pointerHeapMalloc);
   delete pointerHeapNew;

   std::cout << std::endl;

   return 0;
}
```

---

## Aufbau des Programms

- **Teil 1:** Zeigt, wie Pointer auf Stack-Variablen zeigen und wie Änderungen über Pointer und direkte Zuweisung wirken.
- **Teil 2:** Verwendet eine Struktur, zeigt deren Größe, Adresse und Zugriff über Pointer.
- **Teil 3:** Demonstriert dynamische Speicherreservierung mit `malloc`/`free` (C) und `new`/`delete` (C++), prüft auf erfolgreiche Allokation und gibt Werte sowie Adressen aus.

---

## Die Ausgabe

Die Ausgabe könnte z.B. so aussehen (abhängig vom System):

```bash
number1: 7.1, number2: 2
number1: 7.1, number2: 23.2
number1: 0, number2: 23.2

number1: 0
 -> Size of number1: 4

ptrToNumber1: 0
 -> Size of ptrToNumber1: 8

myFirstStruct: 10, 20, 30, 40, 50
 -> Size of myFirstStruct: 20
 -> Address of myFirstStruct: 0x61fe14
 -> Value of myFirstStruct via pointer: 10, 20, 30, 40, 50
 -> Size of pointer to myFirstStruct: 8

Address of pointerHeapMalloc: 0x1f4e2a0
Address of pointerHeapNew: 0x1f4e2c0
Value of pointerHeapMalloc: 3
Value of pointerHeapNew: 4
```

- Die genauen Adressen und Größen können je nach System variieren.
- `number1` ist ein `float` (meist 4 Byte).
- Ein Pointer ist auf 64-Bit-Systemen meist 8 Byte groß.
- Die Strukturgröße ergibt sich aus der Summe der enthaltenen `float`s (hier 5 × 4 Byte = 20 Byte).

---

## Hinweise

- Pointer speichern Speicheradressen und können auf Stack- oder Heap-Variablen zeigen.
- Über das Dereferenzieren (`*ptr`) kann auf den Wert an der Adresse zugegriffen werden.
- Dynamisch reservierter Speicher (Heap) muss mit `free` bzw. `delete` wieder freigegeben werden, um Speicherlecks zu vermeiden.
- Die Größe von Datentypen kann mit `sizeof` ermittelt werden.
- Änderungen über Pointer wirken sich direkt auf die Zielvariable aus.
- Heap-Adressen und Stack-Adressen liegen in unterschiedlichen Speicherbereichen.