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
