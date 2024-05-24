#include <vector>
#include <iostream>

int main()
{
   std::vector<std::string> vec; // std::vector ist ein dynamisches Array von std::string-Objekten
   vec.push_back("Hello ");
   vec.push_back("World");
   vec.push_back("!!");

   std::cout << "Initiale Vectorsize: ";
   std::cout << vec.size() << std::endl;

   unsigned int new_size;
   std::cout << "Geben Sie die neue Vectorsize ein: ";
   std::cin >> new_size;
   if (std::cin.fail()) {
      std::cout << "Fehler beim Einlesen der Zahl." << std::endl;
      return 1;
   }

   vec.resize(new_size);

   vec.pop_back(); // entfernt das letzte element
   vec.erase(vec.begin() + 2); // Entfernt Element an Position 2

   for (std::string& word : vec) // Range-based for loop
   {
      if (word.empty())
      {
         std::cout << " (leer) ";
      }
      else
      {
         std::cout << word;
      }
   }

   return 0;
}