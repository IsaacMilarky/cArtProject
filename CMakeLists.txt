cmake_minimum_required(VERSION 3.10)

#Set the project name
project(Art VERSION 0.02)
enable_testing()

#This part was not explained well in the tutorial.
configure_file(
    "${PROJECT_SOURCE_DIR}/ArtConfig.h.in"
    "${PROJECT_SOURCE_DIR}/ArtConfig.h")

#C++ 11
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

#add_executable(SimpList main.cpp)

#Remove to remove debug symbols.
set(CMAKE_BUILD_TYPE Debug)

# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
add_executable(Art main.cpp splice.cpp)
target_include_directories(Art PRIVATE "${PROJECT_BINARY_DIR}")

target_link_libraries(Art sfml-graphics)

install(TARGETS Art DESTINATION bin)