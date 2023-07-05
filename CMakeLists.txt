cmake_minimum_required(VERSION 3.6)
project(untitled3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# dear student -- in the end, all .h & .cpp source files should be
#  in the following list of SOURCE_FILES
set(SOURCE_FILES
        DblQueue.h
        DblQueue.cpp
        main.cpp)

add_executable(untitled3 ${SOURCE_FILES})