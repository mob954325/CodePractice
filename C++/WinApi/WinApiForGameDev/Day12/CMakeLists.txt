﻿cmake_minimum_required(VERSION 3.13)

project(Day12)

set(CMAKE_CXX_STANDARD 17)
add_executable(window "winMain.cpp" "input.cpp")
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/") #add header file
remove_definitions(-DUNICODE) #remove unicode
