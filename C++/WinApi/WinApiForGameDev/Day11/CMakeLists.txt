﻿cmake_minimum_required(VERSION 3.13)

project(day11)


set(CMAKE_CXX_STANDARD 17)
add_executable(window "winMain.cpp")
remove_definitions(-DUNICODE) #remove unicode
