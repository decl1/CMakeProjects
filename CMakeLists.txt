﻿cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(DataStructure)

include(cmake/function.cmake)   

add_subdirectory(TStack)
add_subdirectory(TList)
add_subdirectory(TQueue)
add_subdirectory(main)
add_subdirectory(Arithmetic)
add_subdirectory(ArithmeticApp)
add_subdirectory(DSU)
add_subdirectory(DSUmain)

option(BTEST "build test?" YES)
if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(tests)   
endif()
