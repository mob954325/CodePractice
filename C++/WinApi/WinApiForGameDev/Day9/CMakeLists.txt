﻿cmake_minimum_required(VERSION 3.13)

project(Day9)

set(CMAKE_CXX_STANDARD 17)
add_executable(main "main.cpp")
remove_definitions(-DUNICODE) #remove unicode
target_include_directories(main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/") #add header file

add_library(dllProject SHARED "dll.cpp")
remove_definitions(-DUNICODE) #remove unicode
target_include_directories(dllProject PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/") #add header file