#include <iostream>
#include <cassert>

// Funktion zur Division von zwei Zahlen mit assert zur Überprüfung des Divisors
double divide(double numerator, double denominator)
{
    assert(denominator != 0 && "Denominator must not be zero");
    return numerator / denominator;
}

// Funktion zur Demonstration der Verwendung von asserts in einem Simulation
void runSimulation(int numberOfIterations)
{
    assert(numberOfIterations > 0 && "Number of iterations must be greater than zero");
    assert(numberOfIterations < 10 && "Number of iterations must not be greater than 10");
    for (int i = 1; i < numberOfIterations; ++i)
    {
        // Beispiel: Berechnung in der Simulation
        double result = divide(100.0, i); // i+1, um Division durch 0 zu vermeiden
        std::cout << "Iteration " << i << ": Result = " << result << std::endl;
    }
}

int main()
{

    // Setzen der Anzahl der Iterationen
    int numberOfIterations = 9;

    // Aufruf der Simulationsfunktion
    runSimulation(numberOfIterations);

    return 0;
}

// Sicherstellen, dass NDEBUG nicht definiert ist
// #ifdef NDEBUG
// #undef NDEBUG
// #endif