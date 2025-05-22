#include <iostream>

enum class Color
{
   red,
   yellow,
   green,
   blue
};


void printColor(Color color)
{
   switch(color)
   {
      case Color::red:
         std::cout << "\033[31mRed\033[0m"; // ANSI-Escape-Codes for colored output
         break;
      case Color::yellow:
         std::cout << "\033[33mYellow\033[0m";
         break;
      case Color::green:
         std::cout << "\033[32mGreen\033[0m";
         break;
      default:
         std::cout << "\033[34mBlue\033[0m";
   }
}


int main()
{
   Color myFavoriteColor = Color::blue;
   int test = myFavoriteColor + Color::red;

   printColor(myFavoriteColor);

   return 0;
}