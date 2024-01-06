cmake_minimum_required(VERSION 3.16)
project(main)

add_executable(main main.cpp
                    shapes.cpp
                    shapes.hpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
