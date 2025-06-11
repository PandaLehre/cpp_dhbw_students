#include <iostream>
#include <cmath>

#include "HumidityCalculator.hpp"

/// \brief Get Sensor Inputs from User
/// \return void
void getSensorInputs(double &temperature, double &relativHumidity)
{
    std::cout << "Temperature in °C: ";
    std::cin >> temperature;

    std::cout << "Relative Humidity in %: ";
    std::cin >> relativHumidity;
};

int main()
{
    double temperature;
    double relativHumidity;

    getSensorInputs(temperature, relativHumidity);

    HumidityCalculator humidityCalc(temperature, relativHumidity);

    const double absoluteHumidity = humidityCalc.calculateAbsoluteHumidity();
    std::cout << "Absolute Humidity: " << absoluteHumidity << " g/m³" << std::endl;

    return 0;
}