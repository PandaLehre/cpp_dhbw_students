#include <iostream> // include the iostream library (header file)

void printHello(); // function prototype (declaration)

int main() // main function
{
   printHello(); // call the function printHello
   return 0; // return 0 to the operating system (0 means no error)
}

void printHello() // function implementation (definition)
{
   std::cout << "Hello World!" << std::endl; // output "Hello World!" to the console
                                             // std::cout is the standard output stream
                                             // std::endl is a manipulator that ends the line and flushes the buffer
}