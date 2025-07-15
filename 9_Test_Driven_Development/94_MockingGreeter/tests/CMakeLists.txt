set(This MockingGreeterTests)

set(Sources
    test_greeter_service.cpp
    ../time_provider.cpp
    ../greeter_service.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PRIVATE GTest::gtest_main GTest::gmock)

add_test(
    NAME ${This}
    COMMAND ${This}
)
