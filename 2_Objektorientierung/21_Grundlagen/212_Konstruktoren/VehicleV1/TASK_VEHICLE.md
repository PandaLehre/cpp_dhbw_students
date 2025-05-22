# Grundlagen C++: Fahrzeugbewegung mit Konstruktoren

Dieses Projekt enthält ein C++-Programm, das die Bewegung eines Fahrzeugs simuliert. Es verwendet Konstruktoren und Destruktoren, um die Initialisierung und das Aufräumen von Objekten zu demonstrieren. Zusätzlich werden Methoden implementiert, um die Bewegung, den Verbrauch und die Betankung eines Fahrzeugs zu simulieren.

---

## Code-Übersicht

### Der Code
```cpp
#include <iostream>
#include <cmath>

class Vehicle
{
public:
   // Default constructor
   Vehicle(std::string name, double position, float consumption)
      : m_name(name), m_position(position), m_avgConsumption(consumption),
      m_totalConsumption(0), m_currentGas(50.0)
   {
      std::cout << "--- CONSTRUCTOR ---" << std::endl;
   }

   // Destructor
   ~Vehicle()
   {
      std::cout << "--- DESTRUCTOR ---" << std::endl;
   }

   // change position of vehicle to new position.
   void driveTo(double position)
   {
      double distance = std::abs(m_position - position);
      double neededGas = distance * m_avgConsumption / 100.0;
      bool distanceDrivable = (neededGas <= m_currentGas);

      if (distanceDrivable)
      {
         m_position = position;
         m_currentGas -= neededGas;
         std::cout << "--- New position is: " << m_position << std::endl;
         std::cout << "    " << "Current gas is: " << m_currentGas << std::endl;

         m_totalConsumption += neededGas;
      }
      else
      {
         std::cout << "!!! Gastank too low to drive to new position !!!" << std::endl;
      }
   }

   // fill up gas tank to 50 l
   void fillUpGas()
   {
      m_currentGas = 50.0;
   }

   // prints total consumption to console
   void printConsumption()
   {
      std::cout << "    " << "Total consumption is " << m_totalConsumption << std::endl;
   }

   // print name of vehicle to console and the maximum distance it can drive with the current gas
   void printName()
   {
      std::cout << "    " << "Name of vehicle is: " << m_name << std::endl;
      std::cout << "    " << "Maximum distance with current gas is: " << m_currentGas / m_avgConsumption * 100 << " km" << std::endl;
   }

private:
   std::string m_name;        // name of vehicle
   double m_position;         // in km
   double m_avgConsumption;   // in l / 100 km
   double m_totalConsumption; // in l
   double m_currentGas;       // in l
};

int main()
{
   Vehicle myVehicle("PORSCHE", 0.0, 10);

   myVehicle.printName();

   for (size_t i = 0; i <= 1000; i += 150)
   {
      myVehicle.driveTo(static_cast<double>(i));
      myVehicle.printConsumption();
   }

   return 0;
}
```

---

### Aufbau des Programms

#### 1. Konstruktor und Destruktor
- **Konstruktor (`Vehicle`)**:
  - Initialisiert die Attribute des Fahrzeugs, wie Name, Position, Durchschnittsverbrauch, Gesamtkraftstoffverbrauch und aktuellen Tankinhalt.
  - Gibt eine Meldung aus, wenn ein Fahrzeugobjekt erstellt wird.
- **Destruktor (`~Vehicle`)**:
  - Gibt eine Meldung aus, wenn ein Fahrzeugobjekt zerstört wird.

#### 2. Attribute der Klasse `Vehicle`
- `m_name`: Der Name des Fahrzeugs.
- `m_position`: Die aktuelle Position des Fahrzeugs in Kilometern.
- `m_avgConsumption`: Der durchschnittliche Kraftstoffverbrauch in Litern pro 100 Kilometer.
- `m_totalConsumption`: Der gesamte Kraftstoffverbrauch in Litern.
- `m_currentGas`: Der aktuelle Tankinhalt in Litern.

#### 3. Methoden der Klasse `Vehicle`
- **`void driveTo(double position)`**:
  - Berechnet die Distanz zwischen der aktuellen und der neuen Position.
  - Überprüft, ob genügend Kraftstoff vorhanden ist, um die Distanz zu fahren.
  - Aktualisiert die Position und den Tankinhalt, wenn die Fahrt möglich ist.
  - Gibt eine Warnung aus, wenn der Tankinhalt nicht ausreicht.
- **`void fillUpGas()`**:
  - Füllt den Tank auf 50 Liter auf.
- **`void printConsumption()`**:
  - Gibt den gesamten Kraftstoffverbrauch aus.
- **`void printName()`**:
  - Gibt den Namen des Fahrzeugs und die maximale Reichweite mit dem aktuellen Tankinhalt aus.

#### 4. `int main()`
- Erstellt ein Fahrzeugobjekt mit dem Namen "PORSCHE", einer Startposition von 0.0 und einem Durchschnittsverbrauch von 10 Litern pro 100 Kilometer.
- Gibt den Namen und die maximale Reichweite des Fahrzeugs aus.
- Simuliert Fahrten in 150-Kilometer-Schritten bis 1000 Kilometer und gibt nach jeder Fahrt den Kraftstoffverbrauch aus.

---

### Die Ausgabe

#### Beispielausgabe
```
--- CONSTRUCTOR ---
    Name of vehicle is: PORSCHE
    Maximum distance with current gas is: 500 km
--- New position is: 150
    Current gas is: 35
    Total consumption is 15
--- New position is: 300
    Current gas is: 20
    Total consumption is 30
--- New position is: 450
    Current gas is: 5
    Total consumption is 45
!!! Gastank too low to drive to new position !!!
    Total consumption is 45
--- DESTRUCTOR ---
```
- Der Konstruktor wird aufgerufen, wenn das Fahrzeug erstellt wird.
- Nach jeder Fahrt wird die neue Position, der verbleibende Tankinhalt und der gesamte Kraftstoffverbrauch ausgegeben.
- Wenn der Tankinhalt nicht ausreicht, wird eine Warnung ausgegeben.
- Der Destruktor wird aufgerufen, wenn das Fahrzeugobjekt zerstört wird.

---

## Kompilieren und Ausführen

### Mit `g++` (GCC Compiler)
1. **Kompilieren**:
   ```bash
   g++ -o task_vehicle task_vehicle.cpp
   ```
   - `-o task_vehicle`: Gibt den Namen der ausführbaren Datei an.

2. **Ausführen**:
   ```bash
   ./task_vehicle
   ```

---

## Erweiterung: Was passiert im Hintergrund?

### Konstruktoren und Destruktoren
- Der Konstruktor wird automatisch aufgerufen, wenn ein Objekt erstellt wird, und initialisiert die Attribute.
- Der Destruktor wird automatisch aufgerufen, wenn ein Objekt zerstört wird, und kann für Aufräumarbeiten verwendet werden.

### Speicherverwaltung
- In diesem Programm wird kein dynamischer Speicher verwendet. Der Compiler verwaltet den Speicher für die Klasse `Vehicle` automatisch.

---

## Fazit

Dieses Programm demonstriert die Verwendung von Konstruktoren und Destruktoren in C++:
- Initialisierung und Aufräumen von Objekten.
- Simulation von Fahrzeugbewegungen und Kraftstoffverbrauch.
- Verwendung von Methoden, um die Funktionalität der Klasse zu kapseln.

Es ist ein idealer Ausgangspunkt, um die Prinzipien der objektorientierten Programmierung in C++ zu erlernen.