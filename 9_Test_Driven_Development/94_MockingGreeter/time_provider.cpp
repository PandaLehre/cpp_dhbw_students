#include "time_provider.h"
#include <ctime>



int RealTimeProvider::getCurrentHour() const {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto tm = *std::localtime(&time_t);
    return tm.tm_hour;
}
