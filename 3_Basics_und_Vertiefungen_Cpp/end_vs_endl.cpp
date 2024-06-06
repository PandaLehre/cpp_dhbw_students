#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello, World!" << std::endl; // Fügt einen Zeilenumbruch ein und flusht den Stream
    // std::endl ist ein Manipulator in der C++-Standardbibliothek, der für die Ausgabe in Streams wie std::cout verwendet wird. Er bewirkt zwei Dinge:
    // Neuzeile einfügen : Fügt einen Zeilenumbruch(newline character) in den Stream ein, ähnlich wie '\n'.
    // Flush des Streams : Flusht den Ausgabestream, d.h., er zwingt alle gepufferten Ausgaben sofort in das Ziel(z.B.Konsole, Datei geschrieben zu werden.Beispiel

    int foo[] = {10, 20, 30, 40, 50};
    std::vector<int> bar;
    // Iteriere über foo: kopiere Elemente in bar:
    for (auto it = std::begin(foo); it != std::end(foo); ++it)
        bar.push_back(*it);
    // Iteriere über bar: schreibe Elemente in std::cout:
    std::cout << "bar contains:";
    for (auto it = std::begin(bar); it != std::end(bar); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // end ist in der C++ Standardbibliothek kein spezieller Manipulator oder Schlüsselwort,
    // sondern in der Standardbibliothek wird end als Funktionsname verwendet, z.B.std::end, um das Ende von Containern zu bestimmen.

    return 0;
}