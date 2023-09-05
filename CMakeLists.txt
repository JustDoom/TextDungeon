cmake_minimum_required(VERSION 3.25)
project(TextDungeon)

set(CMAKE_CXX_STANDARD 23)

add_executable(TextDungeon src/main.cpp src/room.h src/room.cpp)

find_package(Curses REQUIRED)
target_link_libraries(TextDungeon PRIVATE ${CURSES_LIBRARIES})
target_include_directories(TextDungeon PRIVATE ${CURSES_INCLUDE_DIRS})