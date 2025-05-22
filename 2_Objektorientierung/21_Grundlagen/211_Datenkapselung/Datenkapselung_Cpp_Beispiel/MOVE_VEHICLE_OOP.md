# Grundlagen C++: Fahrzeugbewegung (OOP-Ansatz)

Dieses Projekt enthält ein C++-Programm, das die Bewegung eines Fahrzeugs simuliert. Es verwendet objektorientierte Programmierung (OOP), um die Daten und Funktionen in einer Klasse zu kapseln. Dies dient als Einführung in die grundlegenden Konzepte der OOP in C++.

---

## Code-Übersicht

### Der Code
```cpp
#include <iostream>

struct Position
{
   int x = 0;
   int y = 0;
};

class Vehicle
{
public:
   void move(int seconds)
   {
      m_position.x = m_position.x + seconds * m_speed;
      m_position.y = m_position.y;
   }

   void printPosition()
   {
      std::cout << m_position.x << std::endl;
      std::cout << m_position.y << std::endl;
   }

private:
   std::string m_name;
   const int m_speed = 2;
   Position m_position;
};

int main()
{
   int simulationTime = 10;
   Vehicle myVehicle;

   myVehicle.printPosition();
   myVehicle.move(simulationTime);
   myVehicle.printPosition();

   return 0;
}
```

---

### Aufbau des Programms

#### 1. `struct Position`
- Die Struktur `Position` repräsentiert die Position eines Fahrzeugs im 2D-Raum.
- Sie enthält zwei Attribute:
  - `x`: Die x-Koordinate (Standardwert: 0).
  - `y`: Die y-Koordinate (Standardwert: 0).

#### 2. `class Vehicle`
- Die Klasse `Vehicle` repräsentiert ein Fahrzeug und kapselt die Daten und Funktionen, die mit dem Fahrzeug verbunden sind.
- **Attribute:**
  - `m_name`: Der Name des Fahrzeugs (privat).
  - `m_speed`: Die Geschwindigkeit des Fahrzeugs (privat, konstant, Standardwert: 2).
  - `m_position`: Die aktuelle Position des Fahrzeugs, dargestellt durch eine `Position`-Struktur (privat).
- **Methoden:**
  - `void move(int seconds)`: Bewegt das Fahrzeug basierend auf der Zeit und der Geschwindigkeit.
    - Die x-Koordinate wird um `seconds * m_speed` erhöht.
    - Die y-Koordinate bleibt unverändert.
  - `void printPosition()`: Gibt die aktuelle Position des Fahrzeugs auf der Konsole aus.

#### 3. `int main()`
- Die `main()`-Funktion ist der Einstiegspunkt des Programms.
- Ablauf:
  1. Initialisierung der Simulationszeit (`simulationTime`) und eines Fahrzeugs (`myVehicle`).
  2. Ausgabe der Startposition des Fahrzeugs mit `printPosition()`.
  3. Aufruf der `move()`-Methode, um das Fahrzeug zu bewegen.
  4. Ausgabe der neuen Position des Fahrzeugs mit `printPosition()`.

---

### Die Ausgabe

#### Beispielausgabe
```
0
0
20
0
```
- Die erste Zeile zeigt die Startposition des Fahrzeugs (x = 0, y = 0).
- Nach der Bewegung (10 Sekunden bei Geschwindigkeit 2) hat das Fahrzeug die Position (x = 20, y = 0).

---

## Kompilieren und Ausführen

### Mit `g++` (GCC Compiler)
1. **Kompilieren**:
   ```bash
   g++ -o move_vehicle_oop move_vehicle_oop.cpp
   ```
   - `-o move_vehicle_oop`: Gibt den Namen der ausführbaren Datei an.

2. **Ausführen**:
   ```bash
   ./move_vehicle_oop
   ```

---

## Erweiterung: Was passiert im Hintergrund?

### Objektorientierung
- Die Klasse `Vehicle` kapselt die Daten (Attribute) und die zugehörigen Funktionen (Methoden).
- Die Daten sind privat, was bedeutet, dass sie nur über die Methoden der Klasse zugänglich sind. Dies ist ein Beispiel für **Datenkapselung**.

### Compiler und Linker
- Der **Compiler** übersetzt den Code in Maschinencode.
- Der **Linker** verbindet den übersetzten Code mit der Standardbibliothek, um Funktionen wie `std::cout` bereitzustellen.

### Speicherverwaltung
- In diesem Programm wird kein dynamischer Speicher verwendet. Der Compiler verwaltet den Speicher für die Klasse `Vehicle` und die Struktur `Position` automatisch.

---

## Fazit

Dieses Programm demonstriert die Grundlagen der objektorientierten Programmierung in C++:
- Definition und Verwendung von Klassen und Strukturen.
- Implementierung von Methoden, die auf den Daten der Klasse arbeiten.
- Einfache Simulation einer Fahrzeugbewegung.

Es ist ein idealer Ausgangspunkt, um die Prinzipien der OOP in C++ zu erlernen.