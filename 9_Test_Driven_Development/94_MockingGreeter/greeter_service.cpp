#include "greeter_service.h"

GreeterService::GreeterService(TimeProvider* timeProvider) 
    : timeProvider_(timeProvider) {}

std::string GreeterService::greet(const std::string& name) const {
    int hour = timeProvider_->getCurrentHour();
    
    if (hour >= 5 && hour < 12) {
        return "Good morning, " + name + "!";
    } else if (hour >= 12 && hour < 18) {
        return "Good afternoon, " + name + "!";
    } else {
        return "Good evening, " + name + "!";
    }
}
