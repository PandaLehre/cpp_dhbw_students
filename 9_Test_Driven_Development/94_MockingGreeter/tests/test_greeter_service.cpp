#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../greeter_service.h"
#include "../time_provider.h"

class MockTimeProvider : public TimeProvider {
public:
    // Define the mock method for getCurrentHour
    // Arguments: MOCK_METHOD(ReturnType, MethodName, (ArgumentTypes), (Qualifiers))
    MOCK_METHOD(int, getCurrentHour, (), (const, override));
};

class GreeterServiceTest : public ::testing::Test {
protected:
    MockTimeProvider mockTimeProvider;
    GreeterService greeter{&mockTimeProvider};
};

TEST_F(GreeterServiceTest, GreetInMorning_ReturnsGoodMorning) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(8));
    
    std::string result = greeter.greet("Alice");
    EXPECT_EQ(result, "Good morning, Alice!");
}

TEST_F(GreeterServiceTest, GreetAtNoon_ReturnsGoodAfternoon) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(12));
    
    std::string result = greeter.greet("Bob");
    EXPECT_EQ(result, "Good afternoon, Bob!");
}

TEST_F(GreeterServiceTest, GreetInAfternoon_ReturnsGoodAfternoon) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(15));
    
    std::string result = greeter.greet("Charlie");
    EXPECT_EQ(result, "Good afternoon, Charlie!");
}

TEST_F(GreeterServiceTest, GreetInEvening_ReturnsGoodEvening) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(20));
    
    std::string result = greeter.greet("David");
    EXPECT_EQ(result, "Good evening, David!");
}

TEST_F(GreeterServiceTest, GreetAtMidnight_ReturnsGoodEvening) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(0));
    
    std::string result = greeter.greet("Eve");
    EXPECT_EQ(result, "Good evening, Eve!");
}

TEST_F(GreeterServiceTest, GreetEarlyMorning_ReturnsGoodMorning) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(5));
    
    std::string result = greeter.greet("Frank");
    EXPECT_EQ(result, "Good morning, Frank!");
}

TEST_F(GreeterServiceTest, GreetJustBeforeNoon_ReturnsGoodMorning) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(11));
    
    std::string result = greeter.greet("Grace");
    EXPECT_EQ(result, "Good morning, Grace!");
}

TEST_F(GreeterServiceTest, GreetJustBeforeEvening_ReturnsGoodAfternoon) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(17));
    
    std::string result = greeter.greet("Henry");
    EXPECT_EQ(result, "Good afternoon, Henry!");
}

// Edge case tests
TEST_F(GreeterServiceTest, GreetAt4AM_ReturnsGoodEvening) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(4));
    
    std::string result = greeter.greet("Ivy");
    EXPECT_EQ(result, "Good evening, Ivy!");
}

TEST_F(GreeterServiceTest, GreetAt6PM_ReturnsGoodEvening) {
    EXPECT_CALL(mockTimeProvider, getCurrentHour())
        .WillOnce(::testing::Return(18));
    
    std::string result = greeter.greet("Jack");
    EXPECT_EQ(result, "Good evening, Jack!");
}
