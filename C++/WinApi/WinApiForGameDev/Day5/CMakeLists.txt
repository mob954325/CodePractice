﻿cmake_minimum_required(VERSION 3.13)

project(Day5)
set(CMAKE_CXX_STANDARD 17)
add_executable(day5 "Day5.cpp")
remove_definitions(-DUNICODE) #remove unicode
add_compile_definitions(FILE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/")  # 파일 위치 정의