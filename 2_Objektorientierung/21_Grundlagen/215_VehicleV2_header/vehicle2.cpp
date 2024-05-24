#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <chrono>

#include "vehicle2.hpp"


// change position of vehicle to new position.
void Vehicle::driveTo(double position)
{
   double distance = std::abs(m_position - position);
   double neededGas = distance * m_avgConsumption / 100.0;
   bool distanceDrivable = (neededGas <= m_currentGas);

   if (distanceDrivable)
   {
      m_stayAtPosition = false;
      m_position = position;
      m_currentGas -= neededGas;
      printPositionAndGas();
      m_totalConsumption += neededGas;
      printConsumption();
   }
   else
   {
      m_stayAtPosition = true;
      std::cout << "!!! Gastank too low to drive to new position !!!" << std::endl;
      fillUpGas();
   }
}

// fill up gas tank to 50 l
void Vehicle::fillUpGas()
{
   // print out a filling up level wish fills up in 10l in 1 seconds
   for (int i = 0; i <= 50; i += 10)
   {
      std::cout << "    " << "Filling up gas tank to " << i << " l" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
   }
   m_currentGas = 50.0;
}

// print new position and current gas to console
void Vehicle::printPositionAndGas()
{
   std::cout << "--- New position is: " << m_position << std::endl;
   std::cout << "    " << "Current gas is: " << m_currentGas << std::endl;
}

// prints total consumption to console
void Vehicle::printConsumption()
{
   std::cout << "    " << "Total consumption is " << m_totalConsumption << std::endl;
}

// print name of vehicle to console and the maximum distance it can drive with the current gas
void Vehicle::printNameAndRange()
{
   std::cout << "    " << "Name of vehicle is: " << m_name << std::endl;
   std::cout << "    " << "Maximum distance with current gas is: " << m_currentGas / m_avgConsumption * 100 << " km\n"
             << std::endl;
}

// GETTER for m_stayAtPosition
bool Vehicle::getStayAtPosition()
{
   return m_stayAtPosition;
}
