﻿cmake_minimum_required(VERSION 3.13)

project(day1)
set(CMAKE_CXX_STANDARD 17)
add_executable(keylogger "keylogger.cpp")

add_executable(winmain "winmain.cpp")
set_target_properties(winmain PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

set(CMAKE_CXX_STANDARD 17)
add_executable(homework2template "homework2template.cpp")