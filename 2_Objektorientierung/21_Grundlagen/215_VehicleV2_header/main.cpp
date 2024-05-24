#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <chrono>

#include "vehicle2.hpp"

int main()
{
   // Create some places in a static array (C style)
   Place places[] = {
       {"DHBW", 0.0},
       {"Berlin", 630},
       {"Munich", 230},
       {"Hamburg", 650},
       {"Cologne", 360},
   };

   // Create a vehicle object
   Vehicle myVehicle("PORSCHE", 0.0, 25);
   myVehicle.printNameAndRange();
   // ask the user for a destination (based on the static array)
   std::cout << "Where do you want to go?" << std::endl;
   for (size_t i = 0; i < 5; i++)
   {
      std::cout << i << " - " << places[i].placeName << std::endl;
   }
   std::cout << "Please enter a number: ";
   // check if the input is valid
   size_t userInput;
   std::cin >> userInput;
   if (userInput >= 5)
   {
      std::cout << "Invalid input" << std::endl;
      return 1;
   }
   // print the destination and the distance
   else
   {
      std::cout << "You want to go to " << places[userInput].placeName << " which is " << places[userInput].placeDistance << " km away.\n" << std::endl;
   }
   // wait for 2 seconds
   std::this_thread::sleep_for(std::chrono::seconds(2));
   // drive to the destination and print the consumption every distOut km
   size_t distOut = 100;
   for (size_t i = 0; i <= static_cast<size_t>(places[userInput].placeDistance); i += distOut)
   {
      myVehicle.driveTo(static_cast<double>(i));
      bool stayAtPosition = myVehicle.getStayAtPosition();
      if (stayAtPosition == true)
      {
         i -= distOut;
      }
      // wait for 2 seconds
      std::this_thread::sleep_for(std::chrono::seconds(2));
   }
   // print welcome message
   std::cout << "\nWelcome to " << places[userInput].placeName << "!\n" << std::endl;

   return 0;
}


   // // creat some places in a dynamic array
   // Place *placesDynamic = new Place[5]{
   //     {"Home", 0.0},
   //     {"Berlin", 900},
   //     {"Munich", 1200},
   //     {"Hamburg", 800},
   //     {"Cologne", 700},
   // };

   // // create some places in a vector
   // std::vector<Place> placesVector{
   //     {"Home", 0.0},
   //     {"Berlin", 900},
   //     {"Munich", 1200},
   //     {"Hamburg", 800},
   //     {"Cologne", 700},
   // };