cmake_minimum_required(VERSION 3.13)

project(Day15)


set(CMAKE_CXX_STANDARD 17)

#these will automatically add all of the cpp files to the project!
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/game/src/*.cpp")
file(GLOB_RECURSE PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*.cpp")


add_executable(window ${GAME_SOURCES} ${PLATFORM_SOURCES})
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/game/include") #add header file
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/platform/include") #add header file
remove_definitions(-DUNICODE) #remove unicode



