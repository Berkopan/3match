cmake_minimum_required(VERSION 3.14)
project(3-match)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/3.0.0_1/lib/cmake/SFML")
find_package(SFML COMPONENTS Graphics Audio REQUIRED)

include_directories("/opt/homebrew/Cellar/sfml/3.0.0_1/include")

add_executable(3-match main.cpp
        configuration.h)
target_link_libraries(3-match SFML::Graphics SFML::Audio)
