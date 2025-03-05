cmake_minimum_required(VERSION 3.13)

project(Day15_1)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# add all of the cpp files to the project
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/game/src/*.cpp")
file(GLOB_RECURSE PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*.cpp")

add_executable(window ${GAME_SOURCES} ${PLATFORM_SOURCES}) # 해당 파일을 실행파일로 추가
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/game/include") #add header file
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/platform/include") #add header file
remove_definitions(-DUNICODE) #remove unicode