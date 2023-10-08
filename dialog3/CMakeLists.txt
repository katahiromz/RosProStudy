# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(dialog3 CXX RC)

# dialog3.exe
add_executable(dialog3 WIN32 dialog3.cpp dialog3_res.rc)
target_link_libraries(dialog3 comctl32)
