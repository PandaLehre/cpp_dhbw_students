# Grundlagen C++: Zeiger und Referenzen

Dieses Beispiel demonstriert die Unterschiede und Gemeinsamkeiten zwischen Zeigern (Pointer) und Referenzen in C++. Es zeigt, wie Werte über Zeiger und Referenzen verändert werden können und welche Besonderheiten es bei der Verwendung gibt.

---

## Code-Übersicht

```cpp
#include <iostream>

void modifyWithPointer(int* ptr) {
    if (ptr) {
        *ptr = 10;
    }
}

void modifyWithReference(int& ref) {
    ref = 20;
}

int main() {
    int a = 5;
    int b = 5;

    int *ptr = &a;

    int &ref = b;

    std::cout << "Initial values:\n";
    std::cout << "a = " << a << ", b = " << b << "\n";

    modifyWithPointer(ptr);
    std::cout << "After modifyWithPointer(ptr):\n";
    std::cout << "a = " << a << ", b = " << b << "\n";

    modifyWithReference(ref);
    std::cout << "After modifyWithReference(ref):\n";
    std::cout << "a = " << a << ", b = " << b << "\n";

    int c = 15;
    ptr = &c;
    std::cout << "After reassigning ptr to c:\n";
    std::cout << "*ptr = " << *ptr << "\n";

    std::cout << "a = " << a << ", b = " << b << "\n";
    ref = c;
    std::cout << "ref = " << ref << "\n";
    std::cout << "a = " << a << ", b = " << b << "\n";

    return 0;
}
```

---

## Aufbau des Programms

### 1. `modifyWithPointer`

- Nimmt einen Zeiger auf ein `int` entgegen.
- Über den Zeiger kann der Wert der Variablen, auf die gezeigt wird, verändert werden (`*ptr = 10`).
- Zeiger können auf verschiedene Variablen zeigen und auch `nullptr` sein.
- Im Code wird zuerst geprüft, ob der Zeiger nicht `nullptr` ist (`if (ptr)`). Nur wenn der Zeiger auf eine gültige Speicheradresse zeigt, wird der Wert an dieser Adresse auf 10 gesetzt. Das verhindert Zugriffe auf ungültige Speicherbereiche und mögliche Programmabstürze.

### 2. `modifyWithReference`

- Nimmt eine Referenz auf ein `int` entgegen.
- Über die Referenz kann der Wert der referenzierten Variablen direkt verändert werden (`ref = 20`).
- Eine Referenz muss bei der Initialisierung gesetzt werden und kann danach nicht mehr auf eine andere Variable zeigen.

### 3. `main()`

- Initialisiert zwei Variablen `a` und `b`.
- Erstellt einen Zeiger auf `a` und eine Referenz auf `b`.
- Zeigt, wie Werte über Zeiger und Referenzen verändert werden.
- Demonstriert, dass Zeiger neu zugewiesen werden können, Referenzen jedoch nicht.
- Zeigt, dass das Zuweisen eines neuen Werts an die Referenz (`ref = c;`) den Wert der ursprünglichen Variable (`b`) ändert, nicht aber die Referenz selbst.

---

## Die Ausgabe

### Beispielausgabe

```bash
Initial values:
a = 5, b = 5
After modifyWithPointer(ptr):
a = 10, b = 5
After modifyWithReference(ref):
a = 10, b = 20
After reassigning ptr to c:
*ptr = 15
ref = 20
```

- Die Werte von `a` und `b` werden durch die jeweiligen Funktionen verändert.
- Nach dem Neusetzen des Zeigers zeigt dieser auf eine andere Variable (`c`).
- Die Referenz bleibt immer mit der ursprünglichen Variable (`b`) verbunden.

---

## Hinweise

- Zeiger können auf verschiedene Variablen zeigen und auch `nullptr` sein. Sie müssen dereferenziert werden, um auf den Wert zuzugreifen.
- Referenzen sind Aliasnamen für eine Variable und müssen bei der Initialisierung gesetzt werden. Sie können nicht auf eine andere Variable umgebogen werden.
- Zeiger erlauben flexiblere Speicherverwaltung, Referenzen sind sicherer und einfacher zu verwenden, wenn keine Neuzuweisung nötig ist.
- Weitere Informationen zu Zeigern und Referenzen finden sich in der [C++ Pointer](https://en.cppreference.com/w/cpp/language/pointer) und [C++ Referenz](https://en.cppreference.com/w/cpp/language/reference).
