#include <iostream>
#include "AD.hpp"

// FUNCTION DEFINITIONS WITHIN NAMESPACE
namespace AD
{
    void print_vehicle_data_refernce(const Vehicle &vehicle)
    {
        std::cout << "Vehicle ID: " << vehicle.id << '\n';
        std::cout << "Vehicle Velocity [kph]: " << vehicle.velocity << '\n';

        switch (vehicle.lane)
        {
        case Lane::CENTER_LANE:
            std::cout << "Vehicle Lane Association: Center Lane" << '\n';
            break;
        case Lane::RIGHT_LANE:
            std::cout << "Vehicle Lane Association: Right Lane" << '\n';
            break;
        case Lane::LEFT_LANE:
            std::cout << "Vehicle Lane Association: Left Lane" << '\n';
            break;
        default:
            break;
        }
    }

    void print_vehicle_data_pointer(const Vehicle *vehicle)
    {
        std::cout << "Vehicle ID: " << vehicle->id << '\n';
        std::cout << "Vehicle Velocity [kph]: " << vehicle->velocity << '\n';

        switch (vehicle->lane)
        {
        case Lane::CENTER_LANE:
            std::cout << "Vehicle Lane Association: Center Lane" << '\n';
            break;
        case Lane::RIGHT_LANE:
            std::cout << "Vehicle Lane Association: Right Lane" << '\n';
            break;
        case Lane::LEFT_LANE:
            std::cout << "Vehicle Lane Association: Left Lane" << '\n';
            break;
        default:
            break;
        }
    }
}