# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(dialog2 CXX RC)

# dialog2.exe
add_executable(dialog2 WIN32 dialog2.cpp dialog2_res.rc)
target_link_libraries(dialog2 comctl32)
