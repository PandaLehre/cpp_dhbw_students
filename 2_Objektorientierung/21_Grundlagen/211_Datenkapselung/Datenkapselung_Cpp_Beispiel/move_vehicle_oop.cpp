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
      std::cout << "My vehicle position" << std::endl;
      std::cout << "x: " << m_position.x << std::endl;
      std::cout << "y: " << m_position.y << std::endl;
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
