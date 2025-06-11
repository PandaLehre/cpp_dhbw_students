
#include <iostream>
#include <cmath>
#include "HumidityCalculator.hpp"

/// \brief Calculates the absolute humidity.
/// \param [in] temperature as Reference to the temperature in degrees Celsius
/// \param [in] relativeHumidity as Reference to the relative humidity in percent
/// \return void, user inputs are assigned to the references
void getSensorInputs(double &temperature, double &relativeHumidity)
{
    std::cout << "Temperature in °C: ";
    std::cin >> temperature;

    std::cout << "Relative humidity in %: ";
    std::cin >> relativeHumidity;
}

int main()
{
    double temperature;
    double relativeHumidity;
    unsigned int numberOfInstances;

    std::cout << "Enter the number of instances to create: ";
    std::cin >> numberOfInstances;

    std::cout << "------------- HUMIDITY CALCULATOR INSTANCES (HCI) -------------" << std::endl;

    for (unsigned int i = 0; i < numberOfInstances; ++i)
    {
        getSensorInputs(temperature, relativeHumidity);

        const HumidityCalculator humCalculator(temperature, relativeHumidity);
        const double absoluteHumidity = humCalculator.calculateAbsoluteHumidity();
        std::cout << "Absolute humidity: " << absoluteHumidity << " g/m³" << std::endl;

        std::cout << "------------- Instance " << humCalculator.getInstanceCount() << " -------------" << std::endl;
    }

    std::cout << "Total instances created: " << HumidityCalculator::getInstanceCount() << std::endl;
    std::cout << "-------------------- END OF HCI --------------------" << std::endl;

    return 0;
}
