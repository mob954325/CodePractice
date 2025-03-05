cmake_minimum_required(VERSION 3.13)

project(Day6)
set(CMAKE_CXX_STANDARD 17)
add_executable(day6 "Day6.cpp")
remove_definitions(-DUNICODE) #remove unicode
add_compile_definitions(FILE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")  #

add_executable(Mapping2 "Mapping2.cpp")
remove_definitions(-DUNICODE) #remove unicode
add_compile_definitions(FILE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")  #