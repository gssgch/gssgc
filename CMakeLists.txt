cmake_minimum_required(VERSION 3.6)
project(gssgc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES src/linkedList/test.cpp)
set(SOURCE_FILES src/linkedList/test11.c)
set(SOURCE_FILES src/linkedList/LinkedTest.cpp)
add_executable(gssgc ${SOURCE_FILES})