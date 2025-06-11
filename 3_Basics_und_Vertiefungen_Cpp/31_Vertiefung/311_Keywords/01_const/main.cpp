#include <iostream>
#include <cmath>

/// \brief Get Sensor Inputs from User
/// \return void
void getSensorInputs(double &temperature, double &relativHumidity)
{
    std::cout << "Temperature in °C: ";
    std::cin >> temperature;

    std::cout << "Relative Humidity in %: ";
    std::cin >> relativHumidity;
};

/// \brief Calculate absolute humidity based on temperature and rel. humidity.
/// \param [in] temperature as reference in Celsius.
/// \param [in] relativeHumidity as reference in %.
/// \return double absolute humidity in g/m³
double calculateAbsoluteHumidity(const double &temperature, const double &relativHumidity)
{
    const double numerator = 6.112 * std::exp((17.67 * temperature) / (temperature + 243.5)) * relativHumidity * 2.1674;
    const double denominator = 273.15 + temperature;
    const double absoluteHumidity = numerator / denominator;
    return absoluteHumidity;
};

int main()
{
    double temperature;
    double relativHumidity;

    getSensorInputs(temperature, relativHumidity);

    const double absoluteHumidity = calculateAbsoluteHumidity(temperature, relativHumidity);
    std::cout << "Absolute Humidity: " << absoluteHumidity << " g/m³" << std::endl;

    return 0;
}