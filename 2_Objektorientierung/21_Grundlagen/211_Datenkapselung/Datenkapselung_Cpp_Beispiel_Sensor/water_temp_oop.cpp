#include <iostream>
#include <string>

class WaterTemperatureSensor {
public:

    WaterTemperatureSensor(std::string pos, double initial_ambient_temp, double initial_differential_temp, bool active_state)
        : sensorPosition(pos), differentialTemperature(initial_differential_temp), isActive(active_state) 
    {
        std::cout << "WaterTemperatureSensor at " << sensorPosition << " initialized." << std::endl;
        ambientTemperature = checkTemperatureValidity(initial_ambient_temp);
    }

    WaterTemperatureSensor(std::string pos, bool active_state)
        : sensorPosition(pos), ambientTemperature(0.0f), differentialTemperature(0.0f), isActive(active_state) 
    {
        std::cout << "Overloaded constructor with position at '" << sensorPosition << std::endl;
    }

    WaterTemperatureSensor()
        : sensorPosition("Unknown"), ambientTemperature(0.0f), differentialTemperature(0.0f), isActive(false) 
    {
        std::cout << "Base Constructor with sensor position " << sensorPosition << std::endl;
    }

    ~WaterTemperatureSensor()
    {
        std::cout << "WaterTemperatureSensor at " << sensorPosition << " destroyed." << std::endl;
    }
    

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
        if (temp < -273.15f) 
        {
            std::cout << "Invalid temperature: below absolute zero. Setting to -273.15°C." << std::endl;
            return -273.15f;
        }
        return temp;
    }
};

int main() {

    WaterTemperatureSensor sensor1("Water Pump", true);

    sensor1.readDifferentialTemperature();
    sensor1.setAmbientTemperature(20.0);
    sensor1.printWaterTemperature();



    return 0;
}
