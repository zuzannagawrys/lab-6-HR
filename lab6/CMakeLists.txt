cmake_minimum_required(VERSION 3.0.0)
project(lab6_ZG VERSION 1.0.0)

include_directories(./include ./src)

add_executable(output ./src/lab6.cpp ./src/main.cpp)