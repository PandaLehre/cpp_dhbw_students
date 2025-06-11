#ifndef HUMIDITY_CALCULATOR_HPP
#define HUMIDITY_CALCULATOR_HPP

#include <cmath>
#include <iostream>

class HumidityCalculator
{
public:
    HumidityCalculator(double temp, double humidity);

    virtual ~HumidityCalculator();

    double calculateAbsoluteHumidity() const;

    double getTemperature() const;

    double getHumidity() const;

private:
    const double m_temperature;
    const double m_relativeHumidity;
    static constexpr double M_CONSTTANT_FACTOR{6.112 * 2.1674};
};

#endif // !HUMIDITY_CALCULATOR_HPP