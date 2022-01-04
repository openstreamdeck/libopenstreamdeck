cmake_minimum_required(VERSION 3.21)
project(libopenstreamdeck)

# Find dependencies imported by Conan (Dependencies are listed in conanfile.py)

# Run 'conan install .' to generate the missing modules.
# Locally the modules are installed at the root of the project by the previous command.
if ("${CMAKE_MODULE_PATH}" STREQUAL "")
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
endif ()

find_package(Boost REQUIRED)

# Disable compiler check for conan since it cannot recognize XCode 13.
set(CONAN_DISABLE_CHECK_COMPILER true)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(openstreamdeck)
