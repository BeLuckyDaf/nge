cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME NorfoeGameEngine)
project(${PROJECT_NAME})

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(NGE WIN32 src/Entity.cpp src/Crosshair.cpp src/Game.cpp src/SfmlGame.cpp)
target_link_libraries(NGE sfml-graphics sfml-audio)
