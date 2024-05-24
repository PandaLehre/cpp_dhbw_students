#ifndef VIHICLE2_HPP
#define VIHICLE2_HPP

struct Place
{
   const std::string placeName;
   const double placeDistance;
};

class Vehicle
{
public:
   // Default constructor
   Vehicle(std::string name, double position, float consumption)
       : m_name(name), m_position(position), m_avgConsumption(consumption), m_totalConsumption(0), m_currentGas(50.0)
   {
      std::cout << "--- CONSTRUCTOR ---" << std::endl;
   }

   // Destructor
   ~Vehicle()
   {
      std::cout << "--- DESTRUCTOR ---" << std::endl;
   }

   // change position of vehicle to new position.
   void driveTo(double position);

   // fill up gas tank to 50 l
   void fillUpGas();

   // print new position and current gas to console
   void printPositionAndGas();

   // prints total consumption to console
   void printConsumption();

   // print name of vehicle to console and the maximum distance it can drive with the current gas
   void printNameAndRange();

   // GETTER for m_stayAtPosition
   bool getStayAtPosition();

private:
   std::string m_name;        // name of vehicle
   double m_position;         // in km
   double m_avgConsumption;   // in l / 100 km
   double m_totalConsumption; // in l
   double m_currentGas;       // in l
   bool m_stayAtPosition;     // stay at position for refueling gas tank
};

#endif // VIHICLE2_HPP