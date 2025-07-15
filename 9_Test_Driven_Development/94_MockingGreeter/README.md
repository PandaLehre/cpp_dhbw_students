# MockingGreeter Example

This project demonstrates the use of Google Mock (GMock) to test time-dependent functionality by mocking the time provider component.

## Project Structure

- `time_provider.h/.cpp` - Abstract time provider interface and real implementation
- `greeter_service.h/.cpp` - Service that greets users based on current time
- `main.cpp` - Main application demonstrating the greeter
- `tests/` - Unit tests using Google Mock

## Greeting Logic

The greeter provides different greetings based on the hour of the day:
- **5:00 - 11:59**: "Good morning, [name]!"
- **12:00 - 17:59**: "Good afternoon, [name]!"
- **18:00 - 4:59**: "Good evening, [name]!"

## Mocking Strategy

The `TimeProvider` class provides an abstraction layer around time retrieval. This allows us to:
1. Use `RealTimeProvider` in production code
2. Use `MockTimeProvider` in tests to control the time

## Building and Running

```bash
mkdir build
cd build
cmake ..
make
./MockingGreeter
```

## Running Tests

```bash
cd build
make MockingGreeterTests
./tests/MockingGreeterTests
```

## Key Testing Concepts Demonstrated

1. **Dependency Injection**: The `GreeterService` takes a `TimeProvider*` to allow for mocking
2. **Interface Segregation**: `TimeProvider` provides only the minimal interface needed
3. **Testability**: By abstracting time, we can test all time-dependent scenarios deterministically
4. **Mock Objects**: Using GMock to create predictable test doubles
