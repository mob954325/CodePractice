﻿cmake_minimum_required(VERSION 3.13)

project(day8)

set(CMAKE_CXX_STANDARD 17)

add_executable(victim "victim.cpp")
remove_definitions(-DUNICODE) #remove unicode

add_executable(hacker "hacker.cpp")
remove_definitions(-DUNICODE) #remove unicode

add_executable(virtualScanner "virtualScanner.cpp")
remove_definitions(-DUNICODE) #remove unicode

add_executable(playerVirtualScanner "playerVirtualScanner.cpp")
remove_definitions(-DUNICODE) #remove unicode

add_executable(victimPlayer "victimPlayer.cpp")
remove_definitions(-DUNICODE) #remove unicode