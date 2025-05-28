<!-- filepath: c:\PandaStudents\cpp_dhbw_students\3_Basics_und_Vertiefungen_Cpp\30_Basics\303_stdVector_ranged_based_for_loops\VECTOR_STD.md -->
# Grundlagen C++: Arbeiten mit `std::vector` und Range-Based-For-Loops

Dieses Beispiel demonstriert die Verwendung des C++-Standardcontainers `std::vector` sowie verschiedene Möglichkeiten, einen Vektor zu durchlaufen und zu manipulieren.

---

## Code-Übersicht

### Der Code

```cpp
#include <iostream>
#include <vector>

void print_vector_c_style(std::vector<std::string> vec)
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

    print_vector_ranged_for_loop(vec);

    vec[0] = "Hi";
    print_vector_ranged_for_loop(vec);

    vec.pop_back();
    print_vector_ranged_for_loop(vec);

    return 0;
}
```

---

## Aufbau des Programms

### 1. `print_vector_c_style`

- Gibt die Elemente eines Vektors mit einer klassischen for-Schleife aus.
- Im Gegensatz zu C-Arrays muss die Größe nicht separat übergeben werden, da sie über `vec.size()` verfügbar ist.
- Gibt eine Meldung aus, wenn der Vektor leer ist.

### 2. `print_vector_ranged_for_loop`

- Gibt die Elemente eines Vektors mit einer Range-Based-For-Schleife aus.
- Diese Schleife ist moderner und lesbarer als die klassische Variante.
- Gibt eine Meldung aus, wenn der Vektor leer ist.

### 3. `main()`

- Initialisiert einen leeren Vektor.
- Demonstriert das Hinzufügen (`push_back`), Ändern und Entfernen (`pop_back`) von Elementen.
- Gibt die Größe (`size`) und Kapazität (`capacity`) des Vektors aus.
- Zeigt, wie sich die Inhalte des Vektors nach verschiedenen Operationen verändern.

---

## Die Ausgabe

### Beispielausgabe

```bash
Vector is empty!
Vectorsize: 5
Vectorcapacity: 8
Hello World! This is my first std::vector.
Hi World! This is my first std::vector.
Hi World! This is my first std::vector.
```

- Die erste Zeile gibt aus, dass der Vektor zu Beginn leer ist.
- Nach dem Hinzufügen von Elementen werden Größe und Kapazität angezeigt.
- Die weiteren Zeilen zeigen die Inhalte nach Modifikationen.

---

## Kompilieren und Ausführen

### Mit `g++` (GCC Compiler)

1. **Kompilieren**:

   ```powershell
   g++ -o vector vector.cpp
   ```

2. **Ausführen**:

   ```powershell
   ./vector
   ```

---

## Hinweise

- Die Kapazität (`capacity`) eines Vektors kann größer als die aktuelle Größe (`size`) sein, um zukünftige Erweiterungen effizient zu ermöglichen.
- `std::vector` übernimmt die Speicherverwaltung automatisch.
- Range-Based-For-Loops sind ab C++11 verfügbar und werden für die Iteration über Container empfohlen.
- weitere Informationen zu `std::vector` und Range-Based-For-Loops finden sich in der [C++ Standardbibliothek](https://en.cppreference.com/w/cpp/container/vector) und in den [C++ Sprachstandards](https://en.cppreference.com/w/cpp/language/range-for).
