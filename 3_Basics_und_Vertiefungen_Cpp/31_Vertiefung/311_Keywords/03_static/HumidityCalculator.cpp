
#include <cmath>
#include "HumidityCalculator.hpp"

HumidityCalculator::HumidityCalculator(double temp, double humidity)
    : m_temperatureCelsius(temp), m_relativeHumidity(humidity)
{
    m_instanceCount++;
}

int HumidityCalculator::m_instanceCount = 0;

double HumidityCalculator::calculateAbsoluteHumidity() const
{
    const double numerator = M_CONSTANT_FACTOR * std::exp((17.67 * m_temperatureCelsius) / (m_temperatureCelsius + 243.5)) * m_relativeHumidity;
    const double denominator = 273.15 + m_temperatureCelsius;
    const double absoluteHumidity = numerator / denominator;
    return absoluteHumidity;
}

double HumidityCalculator::getTemperature() const
{
    return m_temperatureCelsius;
}

double HumidityCalculator::getRelativeHumidity() const
{
    return m_relativeHumidity;
}

int HumidityCalculator::getInstanceCount()
{
    return m_instanceCount;
}
