#include "HumidityCalculator.hpp"

HumidityCalculator::HumidityCalculator(double temp, double humidity) : m_temperature(temp), m_relativeHumidity(humidity) {}

HumidityCalculator::~HumidityCalculator() {}

/// \brief Calculate absolute humidity based on temperature and rel. humidity.
/// \param [in] temperature as reference in Celsius.
/// \param [in] relativeHumidity as reference in %.
/// \return double absolute humidity in g/m³
double HumidityCalculator::calculateAbsoluteHumidity() const
{
    const double numerator = M_CONSTTANT_FACTOR * std::exp((17.67 * m_temperature) / (m_temperature + 243.5)) * m_relativeHumidity;
    const double denominator = 273.15 + m_temperature;
    const double absoluteHumidity = numerator / denominator;
    return absoluteHumidity;
};

double HumidityCalculator::getTemperature() const
{
    return m_temperature;
};

double HumidityCalculator::getHumidity() const
{
    return m_relativeHumidity;
};