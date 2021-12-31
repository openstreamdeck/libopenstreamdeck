cmake_minimum_required(VERSION 3.21)
project(libopenstreamdeck)

# Disable compiler check for conan since it cannot recognize XCode 13.
set(CONAN_DISABLE_CHECK_COMPILER true)

set(CMAKE_CXX_STANDARD 20)

# Configure dependencies using conan.
# You must install conan and run in terminal: conan install --build=missing .
include(conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(openstreamdeck)
