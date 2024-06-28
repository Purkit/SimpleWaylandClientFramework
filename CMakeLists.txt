cmake_minimum_required(VERSION 3.14)

project(SWCF 
        VERSION 1.0.0
        LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type not set explicitely - Defaulting to 'Release'")
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(src)