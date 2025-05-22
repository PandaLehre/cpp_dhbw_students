#include <iostream>

#include "person.hpp"

int main()
{
   Person jose("Jose", Nationality::es);
   Person daniel("Daniel", Nationality::de);
   Person fabio("Fabio", Nationality::it);
   Person brian("Brian", Nationality::en);
   Person unknown("Unknown");

   jose.greet(jose);
   daniel.greet(daniel);
   fabio.greet(fabio);
   brian.greet(brian);
   unknown.greet(unknown); // Default-Nationalität
   // wird über den überladenen Konstruktor gesetzt
   // enum class entsprechend ergänzt
   // default case in switch-case-Struktur ergänzt

   return 0;
}