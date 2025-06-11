#include <cstdint>

// NAMESPACE DEFINITION
namespace AD
{
    enum class Lane
    {
        RIGHT_LANE,
        CENTER_LANE,
        LEFT_LANE
    };

    struct Vehicle
    {
        std::uint32_t id;
        float velocity;
        Lane lane;
    };

// FUNCTION DECLARATIONS
    void print_vehicle_data_refernce(const Vehicle &vehicle);
    void print_vehicle_data_pointer(const Vehicle *vehicle);
}