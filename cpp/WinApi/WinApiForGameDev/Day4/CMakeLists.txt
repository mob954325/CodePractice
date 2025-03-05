cmake_minimum_required(VERSION 3.13)

project(Day4)
set(CMAKE_CXX_STANDARD 17)
add_executable(dialogBox "Dialogue.cpp")
remove_definitions(-DUNICODE) #remove unicode

set(CMAKE_CXX_STANDARD 17)
add_executable(dialogBox2 "DialogueAbstraction.cpp")
remove_definitions(-DUNICODE) #remove unicode