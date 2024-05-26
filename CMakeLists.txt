cmake_minimum_required(VERSION 3.12...3.27)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# set the project name
project(gameboy)

add_subdirectory(src)
add_subdirectory(tests)