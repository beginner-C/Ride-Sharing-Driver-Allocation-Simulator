# Ride-Sharing Driver Allocation Simulator

A C++ console application that simulates a ride-sharing platform (Uber/Careem style) using Object-Oriented Programming. It matches riders to drivers, calculates surge pricing, splits fare revenue, and tracks ratings.

## Features

- **Ride matching and allocation:** assigns the best available driver to each ride request
- **Surge pricing and distance matrix:** adjusts fares based on demand and supply, and computes distances between locations
- **Payout and revenue split:** divides each fare between the driver and the platform
- **User profiles and ratings:** manages rider/driver profiles and average ratings
- **In-transit telematics:** tracks trip progress while a ride is underway

> Status: in development.

## OOP Concepts Used

- Encapsulation (private data, public methods)
- Inheritance and polymorphism (e.g., `User` -> `Driver` / `Rider`)
- Abstraction (separate header/implementation per module)


## Project Structure

```
.
├── include/    Header files (.h)
├── src/        Source files (.cpp) and main.cpp
├── test/       Tests
├── data/       Sample input data
├── docs/       Documentation
└── README.md
```

## Requirements

- A C++17 compiler (g++, clang++, or MSVC)

## Build and Run

Without CMake:

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o simulator
./simulator        # on Windows: simulator.exe
```



## Example Usage



## Roadmap

- [ ] Implement core classes
- [ ] Add `main.cpp` simulation loop
- [ ] Add CMake build
- [ ] Add unit tests

## Authors


- Sharjeel Hassan
- Minhal Aqeel
- Jibran Ahmad Ch
- Fatima Iqbal
- Anfal Babar
