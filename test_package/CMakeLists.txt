cmake_minimum_required(VERSION 3.21)
project(PackageTest CXX)
set(CMAKE_CXX_STANDARD 20)

# Disable compiler check for conan since it cannot recognize XCode 13.
set(CONAN_DISABLE_CHECK_COMPILER true)

# Find dependencies imported by Conan (Dependencies are listed in conanfile.py)
find_package(Boost REQUIRED MODULE)

add_executable(example example.cpp)
target_link_libraries(example ${CONAN_LIBS})
target_link_libraries(example Boost::boost)
