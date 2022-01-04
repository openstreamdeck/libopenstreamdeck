cmake_minimum_required(VERSION 3.21)
project(libopenstreamdeck)

# Find dependencies
find_package(Boost)

# Disable compiler check for conan since it cannot recognize XCode 13.
set(CONAN_DISABLE_CHECK_COMPILER true)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(openstreamdeck)
