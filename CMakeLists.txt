cmake_minimum_required(VERSION 3.25)
project(TextDungeon)

set(CMAKE_CXX_STANDARD 23)

add_executable(TextDungeon src/main.cpp src/room.h src/room.cpp)
