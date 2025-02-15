cmake_minimum_required(VERSION 3.10)

# Set the project name
project(http-server)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(http-server src/main.cpp)

# Find and link the asio library (assuming it's installed via Homebrew)
find_package(asio REQUIRED)
target_link_libraries(http-server asio::asio)

# Include directories
include_directories(/usr/local/include)
