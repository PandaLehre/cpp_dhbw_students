#ifndef TIME_PROVIDER_H
#define TIME_PROVIDER_H

#include <chrono>

class TimeProvider {
public:
    virtual ~TimeProvider() = default;
    virtual int getCurrentHour() const = 0;
};

class RealTimeProvider : public TimeProvider {
public:
    int getCurrentHour() const override;
};

#endif // TIME_PROVIDER_H
