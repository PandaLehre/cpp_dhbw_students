
#ifndef HUMIDITY_CALCULATOR_HPP
#define HUMIDITY_CALCULATOR_HPP

#include <iostream>

class HumidityCalculator
{
public:
    HumidityCalculator(double temp, double humidity);

    virtual ~HumidityCalculator()
    {
        std::cout << "HumidityCalculator destructor called.\n";
    }

    double calculateAbsoluteHumidity() const;

    double getTemperature() const;

    double getRelativeHumidity() const;

    static int getInstanceCount();

private:
    const double m_temperatureCelsius;
    const double m_relativeHumidity;
    static constexpr double M_CONSTANT_FACTOR{6.112 * 2.167};
    static int m_instanceCount;
};

#endif // !HUMIDITY_CALCULATOR_HPP