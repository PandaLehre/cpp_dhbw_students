#include <iostream>
#include <string>

class WaterTemperatureSensor {
public:
    

    void setAmbientTemperature(double temp) 
    {
        ambientTemperature = checkTemperatureValidity(temp);
    }

    void setActive() 
    {
        isActive = true;
    }

    void setSensorPosition(std::string newPosition)
    {
        sensorPosition = newPosition;
    }

    bool isSensorActive() const 
    {
        return isActive;
    }

    double getCalculatedWaterTemperature() const 
    {
        return ambientTemperature + differentialTemperature;
    }

    void printWaterTemperature() const 
    {
        if (!isActive) {
            std::cout << "Sensor at " << sensorPosition << " is inactive." << std::endl;
            return;
        }
        double water_temp = getCalculatedWaterTemperature();
        std::cout << "Water temperature at " << sensorPosition << ": " << water_temp << "°C." << std::endl;
    }

    void readDifferentialTemperature() 
    {
        std::cout << "Enter differential temperature: ";
        double temp;
        std::cin >> temp;
        differentialTemperature = temp;
    }

private:
    std::string sensorPosition;
    double ambientTemperature;
    double differentialTemperature;
    bool isActive;

    double checkTemperatureValidity(double temp) 
    {
        if (temp < -273.15f) {
            std::cout << "Invalid temperature: below absolute zero. Setting to -273.15°C." << std::endl;
            return -273.15f;
        }
        return temp;
    }
};

int main() {

    WaterTemperatureSensor sensor1;

    sensor1.setSensorPosition("Water Pump");
    sensor1.setActive();
    sensor1.readDifferentialTemperature();
    sensor1.setAmbientTemperature(20.0);
    sensor1.printWaterTemperature();



    return 0;
}
