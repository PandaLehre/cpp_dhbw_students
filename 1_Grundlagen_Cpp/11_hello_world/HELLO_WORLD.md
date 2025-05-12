# Grundlagen C++: Hello World

Dieses Projekt enthält ein einfaches C++-Programm, das die Nachricht **"Hello World!"** auf der Konsole ausgibt. Es dient als Einführung in die grundlegenden Konzepte von C++.

---

## Code-Übersicht

### Der Code
```cpp
#include <iostream>

void printHello();

int main()
{
   printHello();
   return 0;
}

void printHello()
{
   std::cout << "\nHello World!\n" << std::endl;
}
```

---

### Aufbau eines C++-Programms

#### 1. `#include <iostream>`
- Die Zeile `#include <iostream>` bindet die Header-Datei ein, die für die Ein- und Ausgabe in C++ benötigt wird.
- Sie stellt Funktionen wie `std::cout` (für die Ausgabe) und `std::cin` (für die Eingabe) bereit.

#### 2. `void printHello()`
- Diese Funktion ist eine benutzerdefinierte Funktion, die die Nachricht **"Hello World!"** auf der Konsole ausgibt.
- Sie wird in der `main()`-Funktion aufgerufen.
- Die Funktion hat keinen Rückgabewert (`void`), was bedeutet, dass sie keine Werte zurückgibt.
- Der Funktionsprototyp `void printHello();` wird vor der `main()`-Funktion deklariert, um dem Compiler mitzuteilen, dass diese Funktion existiert.
- Der Funktionskörper wird später definiert. Diese Struktur ermöglicht es uns Funktionen in andere Dateien auszulagern.

#### 3. `int main()`
- Die Funktion `main()` ist der Einstiegspunkt eines jeden C++-Programms.
- Der Rückgabewert `int` signalisiert dem Betriebssystem, ob das Programm erfolgreich beendet wurde.
  - `return 0;` bedeutet, dass das Programm ohne Fehler beendet wurde.

#### 4. `{ ... }`
- Die geschweiften Klammern `{}` definieren den Funktionskörper. Alles, was innerhalb dieser Klammern steht, wird ausgeführt, wenn die Funktion aufgerufen wird.

---

### Die Ausgabe
```cpp
std::cout << "\nHello World!\n" << std::endl;
```

#### 1. `std::cout`
- `std::cout` steht für **"Character Output"** und wird verwendet, um Text oder Daten auf die Konsole auszugeben.
- Es gehört zur C++-Standardbibliothek und ist im Namespace `std` definiert.

#### 2. `<<` (Stream-Insertion-Operator)
- Der Operator `<<` leitet die Daten (z. B. Text) in den Ausgabestream `std::cout`.

#### 3. `"\n"`
- `\n` ist ein **Escape-Sequenz-Zeichen**, das einen Zeilenumbruch erzeugt.
- Es sorgt dafür, dass der Text in der Konsole in einer neuen Zeile beginnt oder endet.

#### 4. `std::endl`
- `std::endl` ist ein **Manipulator**, der ebenfalls einen Zeilenumbruch erzeugt.
- Zusätzlich wird der Ausgabepuffer geleert (Flush). Das bedeutet, dass alle zwischengespeicherten Daten sofort auf die Konsole geschrieben werden.

---

## Kompilieren und Ausführen

### Mit `g++` (GCC Compiler)
1. **Kompilieren**:
   ```bash
   g++ -o hello_world hello_world.cpp
   ```
   - `-o hello_world`: Gibt den Namen der ausführbaren Datei an.

2. **Ausführen**:
   ```bash
   ./hello_world
   ```

---

## Erweiterung: Was passiert im Hintergrund?

### Compiler und Linker
- Der **Compiler** übersetzt den Code in Maschinencode.
- Der **Linker** verbindet den übersetzten Code mit der Standardbibliothek, um Funktionen wie `std::cout` bereitzustellen.

### Speicherverwaltung
- In diesem Programm wird kein dynamischer Speicher verwendet. Der Compiler verwaltet den Speicher für die Funktion `main()` und `printHello()` automatisch.
