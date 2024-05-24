#include <iostream>
#include <vector>

// Basis Klasse
class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
      std::cout << "___ Shape constructor called ___" << std::endl;
   }

   Shape(double size)
       : m_width(size), m_height(size)
   {
      std::cout << "___ Shape constructor called ___" << std::endl;
   }

   virtual ~Shape() // virtual destructor, damit der Destruktor von den abgeleiteten Klassen aufgerufen werden kann
   {
      std::cout << "___ Shape destructor called ___" << std::endl;
   }

   void setWidth(double width)
   {
      m_width = width;
   }

   void setHeight(double height)
   {
      m_height = height;
   }

   double getHeigth()
   {
      return m_height;
   }

   double getWidth()
   {
      return m_width;
   }

   virtual double getArea() // virtual, damit die abgeleiteten Klassen die Methode überschreiben können
   {
      std::cout << "Error: getArea() not implemented for a generic shape!" << std::endl;
      return 0.0;
   }

   virtual void printArea() // virtual, damit die abgeleiteten Klassen die Methode überschreiben können
   {
      std::cout << "Error: printArea() not implemented for a generic shape!" << std::endl;
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

   Rectangle(double size) // überladener Konstruktor
       : Shape(size)
   {
   }

   ~Rectangle() // Destruktor
   {
      std::cout << "___ Rectangle destructor called ___" << std::endl;
   }

   double getArea() override // override, damit wird gekennzeichnet, dass die Methode von der Basisklasse überschrieben wird
   {
      return (m_width * m_height);
   }

   void printArea() override // override, damit wird gekennzeichnet, dass die Methode von der Basisklasse überschrieben wird
   {
      std::cout << "Total rectangle area: " << this->getArea() << std::endl;
   }
};

// Derived class / Kinderklasse
class Triangle : public Shape
{
public:
   Triangle(double width, double height)
       : Shape(width, height)
   {
   }

   Triangle(double size) // überladener Konstruktor
       : Shape(size)
   {
   }

   ~Triangle() // Destruktor
   {
      std::cout << "___ Triangle destructor called ___" << std::endl;
   }

   double getArea() override // override, damit wird gekennzeichnet, dass die Methode von der Basisklasse überschrieben wird
   {
      return (m_width * m_height * 0.5);
   }

   void printArea() override // override, damit wird gekennzeichnet, dass die Methode von der Basisklasse überschrieben wird
   {
      std::cout << "Total triangle area: " << this->getArea() << std::endl;
   }
};

int main()
{
   Rectangle rectangle(5.1, 7.2);
   rectangle.printArea();
   std::cout << "--- is calculated based on values: " << rectangle.getHeigth() << " and " << rectangle.getWidth() << std::endl;
   std::cout << "------------------------------------------" << std::endl;

   Triangle triangle(5.1, 7.2);
   triangle.printArea();
   std::cout << "--- is calculated based on values: " << triangle.getHeigth() << " and " << triangle.getWidth() << std::endl;
   std::cout << "------------------------------------------" << std::endl;

   Triangle triangle2(5.1);
   triangle2.printArea();
   std::cout << "--- is calculated based on values: " << triangle2.getHeigth() << " and " << triangle2.getWidth() << std::endl;
   std::cout << "------------------------------------------" << std::endl;

   return 0;
}
