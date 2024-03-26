cmake_minimum_required(VERSION 3.2)

project(DnTools VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
    src/main.cpp 
    src/Encounter.cpp 
    include/DnTools/Calculator.hpp 
    include/DnTools/Encounter.hpp)
add_executable(DnTools ${SOURCES})

target_include_directories(DnTools PRIVATE include/DnTools)
target_include_directories(DnTools PRIVATE src)
