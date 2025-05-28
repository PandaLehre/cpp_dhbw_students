#include <iostream>
#include <vector>

void print_vector_c_style(std::vector<std::string> vec)
// Frage: was ist anders im Vergleich zu C Style Implementierungen für dynamische Arrays?
// C: Style: size muss mit übergeben werden. Hier nicht, da Size Methode in Container verfügbar
{
    if (vec.empty())
    {
        std::cout << "Vector is empty!" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

void print_vector_ranged_for_loop(std::vector<std::string> vec)
{
    if (vec.empty())
    {
        std::cout << "Vector is empty!" << std::endl;
        return;
    }
    for (std::string &element : vec)
    {
        std::cout << element;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> vec;

    print_vector_c_style(vec);

    vec.push_back("Hello");
    vec.push_back(" ");
    vec.push_back("World");
    vec.push_back("!");
    vec.push_back(" This is my first std::vector.");

    std::cout << "Vectorsize: " << vec.size() << std::endl;
    std::cout << "Vectorcapacity: " << vec.capacity() << std::endl;
    // Frage: Warum ist die Kapazität des Vectors größer als die Größe?
    // Antwort: Die Kapazität ist die Anzahl der Elemente, die der Vektor ohne Neuanpassung aufnehmen kann.
    // Die Größe ist die Anzahl der tatsächlich enthaltenen Elemente.
    // Die Kapazität kann größer sein, um zukünftige Erweiterungen zu ermöglichen, ohne dass der Vektor neu zugewiesen werden muss.

    print_vector_ranged_for_loop(vec);

    vec[0] = "Hi";
    print_vector_ranged_for_loop(vec);

    vec.pop_back();
    print_vector_ranged_for_loop(vec);


    return 0;
}