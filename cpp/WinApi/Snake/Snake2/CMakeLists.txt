cmake_minimum_required(VERSION 3.13)

project(Snake2)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/game/src/*.cpp")
file(GLOB_RECURSE PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*.cpp")

add_executable(window ${GAME_SOURCES} ${PLATFORM_SOURCES})
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/game/include")
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/platform/include")
remove_definitions(-DUNICODE) #remove unicode