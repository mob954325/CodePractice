﻿cmake_minimum_required(VERSION 3.13)

project(Day10)

set(CMAKE_CXX_STANDARD 17)
add_executable(main "main.cpp")
remove_definitions(-DUNICODE) #remove unicode

set(CMAKE_CXX_STANDARD 17)
add_executable(homeworkSolution "homeworkSolution.cpp")
remove_definitions(-DUNICODE) #remove unicode