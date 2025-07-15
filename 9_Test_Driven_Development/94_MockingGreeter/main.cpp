#include <iostream>
#include "greeter_service.h"
#include "time_provider.h"

int main() {
    RealTimeProvider timeProvider;
    GreeterService greeter(&timeProvider);
    
    std::cout << greeter.greet("Alice") << std::endl;
    std::cout << greeter.greet("Bob") << std::endl;
    
    return 0;
}
