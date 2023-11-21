cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(DataStructure)


include(cmake/function.cmake)   
                                 

add_subdirectory(TStack)
add_subdirectory(TList)   
add_subdirectory(main)
add_subdirectory(Arithmetic)        

option(BTEST "build test?" NO)

if(BTEST)                       
    add_subdirectory(gtest)
    add_subdirectory(tests)     
endif()
