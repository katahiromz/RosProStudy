# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(msgbox C RC)

# msgbox.exe
add_executable(msgbox WIN32 msgbox.c)
