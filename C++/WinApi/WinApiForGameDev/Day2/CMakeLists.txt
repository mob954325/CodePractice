﻿cmake_minimum_required(VERSION 3.13)

project(Day2)
set(CMAKE_CXX_STANDARD 17)
add_executable(colors "colors.cpp")

add_executable(cursor "cursor.cpp")

add_executable(consoleBuffer "consoleBuffer.cpp")

add_executable(winmainconsole "winmainconsole.cpp")
set_target_properties(winmainconsole PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")