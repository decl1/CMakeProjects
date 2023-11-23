cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(DataStructure)


include(cmake/function.cmake)   
                                 

add_subdirectory(TStack)
add_subdirectory(TList)
add_subdirectory(DSU)
add_subdirectory(DSUApp)  
add_subdirectory(DebugMain)

option(BTEST "build test?" YES)

if(BTEST)                       
    add_subdirectory(gtest)
    add_subdirectory(tests)     
endif()
