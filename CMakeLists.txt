cmake_minimum_required(VERSION 3.22)
project(3-match LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio)

add_executable(3-match main.cpp
        configuration.h)
target_link_libraries(3-match PRIVATE SFML::Graphics SFML::Audio)
