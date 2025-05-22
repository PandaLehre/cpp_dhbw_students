#include <iostream>

struct Position
{
   int x = 0;
   int y = 0;
};

class Vehicle
{
public: // per default ist in einer Klasse alles private -> keyword public erlaubt Zugriff auf die Methoden
   Vehicle() : m_name(), m_speed(1), m_position() {};
   // Konstruktoren sind spezielle Methoden, die beim Erstellen eines Objektes aufgerufen werden
   // Sie haben den gleichen Namen wie die Klasse und keinen Rückgabewert
   // Der Standardkonstruktor wird aufgerufen, wenn kein Argument übergeben wird, um den notwendigen Speicherplatz zu reservieren

   Vehicle(std::string name, int speed, Position position) : m_name(name), m_speed(speed), m_position(position) {};
   // Der Konstruktor mit Argumenten wird aufgerufen, wenn Argumente übergeben werden (Überladung)
   // Dieser Konstruktor initialisiert die Attribute der Klasse mit den übergebenen Argumenten
   // Die Initialisierung erfolgt in der Reihenfolge, in der die Attribute deklariert sind d.h. hier: m_name, m_speed, m_position

   ~Vehicle() {};
   // Destruktor wird aufgerufen, wenn das Objekt nicht mehr benötigt wird
   // Er wird verwendet, um den Speicherplatz freizugeben, der für das Objekt reserviert wurde

   void move(int seconds)
   {
      m_position.x = m_position.x + seconds * m_speed;
      m_position.y = m_position.y;
   }

   void printPosition()
   {
      std::cout << "My vehicle position: " << m_name << std::endl;
      std::cout << "x: " << m_position.x << std::endl;
      std::cout << "y: " << m_position.y << std::endl;
   }

   // private:
   std::string m_name;
   int m_speed;
   Position m_position;
};

int main()
{
   int simulationTime = 10;
   Position startPosition{1, 10}; // Uniform Initialization

   Vehicle myVehicle("Porsche", 50, startPosition);

   myVehicle.printPosition();
   myVehicle.move(simulationTime);
   myVehicle.printPosition();

   startPosition.y = 20;
   Vehicle myVehicle2("Mercedes", 20, startPosition);

   myVehicle2.printPosition();
   myVehicle2.move(simulationTime);
   myVehicle2.printPosition();

   return 0;
}