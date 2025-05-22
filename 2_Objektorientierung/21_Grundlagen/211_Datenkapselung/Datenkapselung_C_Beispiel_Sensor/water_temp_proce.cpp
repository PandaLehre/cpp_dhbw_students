// C-Style Beispiel für Wasser Temperatur Sensor
// Erstellen Sie ein äquivalentes Objektorientiertes Beispiel in C++, welches
// die Prinzipien der Datenkapselung und der Abstraktion verwendet.

#include <iostream>
#include <string>

struct WaterTemperatureSensor 
{
    std::string sensorPosition;
    double differentialTemperature;
    double ambientTemperature;
    bool isActive;
};

double calculateWaterTemperature(WaterTemperatureSensor sensor) 
{
    if (sensor.isActive) {
        double waterTemperature = sensor.ambientTemperature + sensor.differentialTemperature;
        return waterTemperature;
    } else {
        std::cout << "Sensor at " << sensor.sensorPosition << " is inactive." << std::endl;
        return -1;
    }
}

void printWaterTemperature(WaterTemperatureSensor sensor) 
{
    double waterTemperature = calculateWaterTemperature(sensor);
    if (waterTemperature != -1) {
        std::cout << "Water temperature at " << sensor.sensorPosition << ": " << waterTemperature << "°C" << std::endl;
    }
}

double checkTemperatureValidity(double temp) 
{
    if (temp < -273.15f) {
        std::cout << "Invalid temperature: below absolute zero. Setting to -273.15°C." << std::endl;
        return -273.15f;
    }
    return temp;
}

double readDifferentialTemperature() 
{
    double temp;
    std::cout << "Enter differential temperature: ";
    std::cin >> temp;
    return temp;
}

int main() {

    WaterTemperatureSensor sensor1;

    sensor1.sensorPosition = "Water Pump";
    sensor1.isActive = true;
    sensor1.differentialTemperature = readDifferentialTemperature();
    sensor1.ambientTemperature = checkTemperatureValidity(20.0);
    sensor1.isActive = true;

    printWaterTemperature(sensor1);

    return 0;
}
