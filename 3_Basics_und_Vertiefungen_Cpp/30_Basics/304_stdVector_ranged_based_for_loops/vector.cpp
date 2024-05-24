#include <vector> // Vector-Container für dynamische Arrays in C++
#include <iostream>

int main()
{
   std::vector<std::string> vec; // Initialisierung eines Vectors mit Strings

   vec.push_back("Hello");
   vec.push_back(" ");
   vec.push_back("World");
   vec.push_back(" ");
   vec.push_back("!!");

   std::cout << "Vectorsize: " << vec.size() << std::endl; // Ausgabe der Größe des Vectors
   std::cout << "Vectorcapacity: " << vec.capacity() << std::endl; // Ausgabe der Kapazität des Vectors  

   // Frage: Warum ist die Kapazität des Vectors größer als die Größe?

   // Zugriff auf die Elemente des Vectors mit einer Range-Based-For-Schleife
   for (std::string& element : vec)
   {
      std::cout << element;
   }

   // Modifikation des Vectors
   vec[0] = "Hi";
   vec[2] = "Universe";
   vec.pop_back(); // Entfernen des letzten Elements

   std::cout << std::endl;

   // Zugriff auf die Elemente des Vectors mit einer Range-Based-For-Schleife
   for (std::string& newElement : vec)
   {
      std::cout << newElement;
   }

   return 0;
}