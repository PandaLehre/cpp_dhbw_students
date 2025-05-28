# Grundlagen C++: Fahrzeugbewegung (C-Style)

Dieses Projekt enthält ein einfaches C-Style-Programm, das die Bewegung eines Fahrzeugs simuliert. Es dient als Einführung in die grundlegenden Konzepte der Datenkapselung und der Verwendung von Strukturen in C++.

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

struct Vehicle
{
   std::string name;
   int speed = 2;
   Position position;
};

void move(Vehicle& vehicle, int seconds)
{
   vehicle.position.x = vehicle.position.x + seconds * vehicle.speed;
   vehicle.position.y = vehicle.position.y;
}

int main()
{
   int simulationTime = 10;
   Vehicle myVehicle;

   std::cout << std::endl;
   std::cout << myVehicle.position.x << std::endl;
   std::cout << myVehicle.position.y << std::endl;

   move(myVehicle, simulationTime);

   std::cout << myVehicle.position.x << std::endl;
   std::cout << myVehicle.position.y << std::endl;

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

#### 2. `struct Vehicle`
- Die Struktur `Vehicle` repräsentiert ein Fahrzeug mit folgenden Attributen:
  - `name`: Der Name des Fahrzeugs (Standardwert: leerer String).
  - `speed`: Die Geschwindigkeit des Fahrzeugs (Standardwert: 2).
  - `position`: Die aktuelle Position des Fahrzeugs, dargestellt durch eine `Position`-Struktur.

#### 3. `void move(Vehicle& vehicle, int seconds)`
- Diese Funktion simuliert die Bewegung eines Fahrzeugs basierend auf seiner Geschwindigkeit und der Zeit.
- Parameter:
  - `vehicle`: Referenz auf das Fahrzeug, dessen Position geändert werden soll.
  - `seconds`: Die Zeit in Sekunden, für die das Fahrzeug bewegt wird.
- Funktionsweise:
  - Die x-Koordinate wird um `seconds * speed` erhöht.
  - Die y-Koordinate bleibt unverändert.

#### 4. `int main()`
- Die `main()`-Funktion ist der Einstiegspunkt des Programms.
- Ablauf:
  1. Initialisierung der Simulationszeit (`simulationTime`) und eines Fahrzeugs (`myVehicle`).
  2. Ausgabe der Startposition des Fahrzeugs.
  3. Aufruf der `move()`-Funktion, um das Fahrzeug zu bewegen.
  4. Ausgabe der neuen Position des Fahrzeugs.

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
   g++ -o move_vehicle move_vehicle_proce.cpp
   ```
   - `-o move_vehicle`: Gibt den Namen der ausführbaren Datei an.

2. **Ausführen**:
   ```bash
   ./move_vehicle
   ```

---

## Erweiterung: Was passiert im Hintergrund?

### Compiler und Linker
- Der **Compiler** übersetzt den Code in Maschinencode.
- Der **Linker** verbindet den übersetzten Code mit der Standardbibliothek, um Funktionen wie `std::cout` bereitzustellen.

### Speicherverwaltung
- In diesem Programm wird kein dynamischer Speicher verwendet. Der Compiler verwaltet den Speicher für die Strukturen `Position` und `Vehicle` automatisch.
