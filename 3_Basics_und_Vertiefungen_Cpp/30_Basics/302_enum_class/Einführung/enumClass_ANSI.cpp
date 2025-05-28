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
   switch (color)
   {
   case Color::red:
      std::cout << "\033[31mRed\033[0m\n"; // ANSI-Escape-Codes for colored output
      break;
   case Color::yellow:
      std::cout << "\033[33mYellow\033[0m\n";
      break;
   case Color::green:
      std::cout << "\033[32mGreen\033[0m\n";
      break;
   default:
      std::cout << "\033[34mBlue\033[0m\n";
   }
}

int main()
{
   Color myFavoriteColor = Color::blue;

   printf("Your favorite color is:\t\t\t");
   printColor(myFavoriteColor);

   int test2 = static_cast<int>(myFavoriteColor) - 1;
   printf("Your favorite color minus one is:\t");
   printColor(static_cast<Color>(test2));

   int test3 = static_cast<int>(myFavoriteColor) - static_cast<int>(Color::yellow);
   printf("Your favorite color minus yellow is:\t");
   printColor(static_cast<Color>(test3));

   return 0;
}