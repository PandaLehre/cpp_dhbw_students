#include <iostream>
#include <vector>

// Basis Klasse
class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
   }

   void setWidth(double width)
   {
      m_width = width;
   }

   void setHeight(double height)
   {
      m_height = height;
   }

protected: // protected, damit die abgeleiteten Klassen darauf zugreifen können
   double m_width;
   double m_height;
};

// Derived class / Kinderklasse
class Rectangle : public Shape
{
public:
   Rectangle(double width, double height)
       : Shape(width, height)
   {
   }

   double getArea()
   {
      return (m_width * m_height);
   }

   void printArea()
   {
      std::cout << "Total rectangle area: " << getArea() << std::endl;
   }
};

int main()
{
   Rectangle rectangle(5.0, 7.0);
   rectangle.printArea();

   return 0;
}

// Sollten nicht alle shapes eine printArea() Methode haben?