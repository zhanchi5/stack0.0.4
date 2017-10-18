cmake_minimum_required(VERSION 3.0.0)
project(${CMAKE_PROJECT_NAME}_lib CXX)

file(GLOB SOURCES *.cpp)
add_library(${PROJECT_NAME} ${SOURCES})
