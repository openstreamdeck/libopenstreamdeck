cmake_minimum_required(VERSION 3.21)
project(libopenstreamdeck)
set(CMAKE_CXX_STANDARD 20)

# Disable compiler check for conan since it cannot recognize XCode 13.
set(CONAN_DISABLE_CHECK_COMPILER true)

# Find dependencies imported by Conan (Dependencies are listed in conanfile.py)

# Run 'conan install .' to generate the missing modules.
# Locally the modules are installed at the root of the project by the previous command.
if ("${CMAKE_MODULE_PATH}" STREQUAL "")
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
endif ()

find_package(Boost REQUIRED MODULE)

add_subdirectory(openstreamdeck)
