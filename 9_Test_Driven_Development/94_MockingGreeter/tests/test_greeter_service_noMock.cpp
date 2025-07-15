#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../greeter_service.h"
#include "../time_provider.h"


class GreeterServiceTest : public ::testing::Test {
protected:
    TimeProvider TimeProvider;
    GreeterService greeter{&mockTimeProvider};
};

TEST_F(GreeterServiceTest, GreetInMorning_ReturnsGoodMorning) {
    std::string result = greeter.greet("Alice");
    EXPECT_EQ(result, "Good morning, Alice!");
}

