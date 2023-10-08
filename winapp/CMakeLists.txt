# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(winapp CXX RC)

# winapp.exe
add_executable(winapp WIN32 winapp.cpp)
target_link_libraries(winapp comctl32)
