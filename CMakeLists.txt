cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(DataStructure)


include(cmake/function.cmake)   
                                 

add_subdirectory(TStack)
add_subdirectory(TList)   
add_subdirectory(DebugMain)
add_subdirectory(Arithmetic)
add_subdirectory(ArithmeticApp)

option(BTEST "build test?" NO)

if(BTEST)                       
    add_subdirectory(gtest)
    add_subdirectory(tests)     
endif()
