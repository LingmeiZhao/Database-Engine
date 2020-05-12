cmake_minimum_required(VERSION 3.5)

project(DatabaseEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include/)

file(GLOB SOURCES "src/*.cpp")

add_executable(DatabaseEngine main.cpp ${SOURCES})
