#ifndef GREETER_SERVICE_H
#define GREETER_SERVICE_H

#include <string>
#include "time_provider.h"

class GreeterService {
public:
    GreeterService(TimeProvider* timeProvider);
    std::string greet(const std::string& name) const;

private:
    TimeProvider* timeProvider_;
};

#endif // GREETER_SERVICE_H
