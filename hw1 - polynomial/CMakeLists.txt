cmake_minimum_required(VERSION 3.29)
project(PracticeHW1)

set(CMAKE_CXX_STANDARD 17)

add_executable(PracticeHW1 src/main.cpp
        src/util/Polynomial.cpp
        src/util/Polynomial.h)
