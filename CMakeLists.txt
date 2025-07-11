cmake_minimum_required(VERSION 3.16)
project(DockerSandbox VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Include directories
include_directories(src)

# Create utility library
add_library(utils
    src/utils/logger.cpp
    src/utils/config.cpp
)

# Create math library
add_library(math_lib
    src/math/calculator.cpp
)

# Create main executable
add_executable(sandbox_app src/main.cpp)

# Link libraries
target_link_libraries(sandbox_app utils math_lib)

# Install rules
install(TARGETS sandbox_app DESTINATION bin)

# CPack configuration for packaging
include(CPack)
set(CPACK_PACKAGE_NAME "DockerSandbox")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "A C++ sandbox application for Docker testing")
