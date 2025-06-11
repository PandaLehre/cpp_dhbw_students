#include "AD.hpp"

int main()
{
    // 1. Fully Qualified Name (direkte Initialisierung)
    const AD::Vehicle v1{1, 22.0F, AD::Lane::LEFT_LANE};
    AD::print_vehicle_data_refernce(v1);
    AD::print_vehicle_data_pointer(&v1);

    // 2. Uniform Initialization (gleichförmige Initialisierung)
    const AD::Vehicle v2 = {2, 33.0F, AD::Lane::RIGHT_LANE};
    AD::print_vehicle_data_refernce(v2);
    AD::print_vehicle_data_pointer(&v2);

    // 3. Designated Initializer (benannte Initialisierung)
    const auto v3 = AD::Vehicle{.id = 1, .velocity = 22.0F, .lane = AD::Lane::LEFT_LANE};
    AD::print_vehicle_data_refernce(v3);
    AD::print_vehicle_data_pointer(&v3);

    return 0;
}