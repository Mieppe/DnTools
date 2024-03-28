cmake_minimum_required(VERSION 3.2)

project(DnTools VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.6.3/gcc_64")
# find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

set(SOURCES 
    src/main.cpp 
    src/Encounter.cpp 
    src/mainWindow.cpp
    src/mainwindow.ui
    include/DnTools/Calculator.hpp 
    include/DnTools/Encounter.hpp
    include/DnTools/mainWindow.hpp)
add_executable(DnTools ${SOURCES})

# target_link_libraries(DnTools PRIVATE Qt6::Core)
target_link_libraries(DnTools PRIVATE Qt6::Widgets)
set_target_properties(DnTools PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


target_include_directories(DnTools PRIVATE include/DnTools)
target_include_directories(DnTools PRIVATE src)
