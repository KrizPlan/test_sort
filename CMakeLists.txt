cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD_REQUIRED 14)
project(test_sort)

find_package( Threads )
add_executable(test_sort main.cpp)
target_link_libraries( test_sort ${CMAKE_THREAD_LIBS_INIT} )