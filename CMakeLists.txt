cmake_minimum_required(VERSION 3.20)
project(TextDungeon
LANGUAGES CXX
VERSION 1.0
)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)

find_package(Curses REQUIRED)
if(APPLE)
    target_link_libraries(YourTargetName PRIVATE curses)
else ()
    target_link_libraries(TextDungeon PRIVATE ${CURSES_LIBRARIES})
endif()
target_include_directories(TextDungeon PRIVATE ${CURSES_INCLUDE_DIRS})