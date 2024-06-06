#include <iostream>

void initAndPrint(double val, int val2)
{
   int intFromDouble = val; // if val == 7.9, intFromDouble becomes 7 (bad)
   char charFromInt = val2; // if val2 == 1025, charFromInt becomes 1 (bad)
   // int intFromDouble{val}; // error: possible truncation (good)
   // char charFromInt{val2}; // error: possible narrowing (good)
   char charFromValue{24}; // OK: 24 can be represented exactly as doubleAuto char (good)
   // char c5{264}; // error (assuming 8-bit chars): 264 cannot be
   //               // represented as doubleAuto char (good)
   // int x4{2.0};  // error: no double to int value conversion (good)
   std::cout << "intFromDouble = " << intFromDouble << "\n"
             << "charFromInt = " << charFromInt << "\n"
            //  << "intFromDouble = " << intFromDouble << "\n"
             << "charFromInt = " << std::isprint(charFromInt) << " " << charFromInt << "\n" // isprint() gibt 0 zurück, wenn char nicht
             << "charFromInt_static_cast_to_int = "  << static_cast<int>(charFromInt) << "\n"
             << "charFromValue = " << charFromValue << "\n" << std::endl;
            //  << "c5 = " << c5 << "\n"
            //  << "x4 = " << x4 << std::endl;
}

int main()
{
   auto doubleAuto{1.1};  // double
   auto intAuto{1025};     // int
   // auto c;              // error
   // c = intAuto;         // error

   initAndPrint(doubleAuto, intAuto);

   // auto doubleAuto{5};        // ok, aber schlechter lesbar
   // int e{5.5};       // int hier besser als auto, da Compiler einen Fehler wirft und mich schützt
   // auto intAuto{Class()};  // preferierte Initalisierung
   // auto c = Class(); // nicht preferierte Initalisierung
   // auto d{intAuto};        // Vermeiden, da schlechter lesbar

   return 0;
}