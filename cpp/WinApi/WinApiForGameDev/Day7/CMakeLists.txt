cmake_minimum_required(VERSION 3.13)

project(Day7)

set(CMAKE_CXX_STANDARD 17)

add_executable(day7 "Day7.cpp")
remove_definitions(-DUNICODE) #remove unicode
add_compile_definitions(FILE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")  #

add_executable(day7_2 "Day7_2.cpp")
remove_definitions(-DUNICODE) #remove unicode
add_compile_definitions(FILE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")  #