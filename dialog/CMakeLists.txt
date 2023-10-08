# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(args C RC)

# dialog.exe
add_executable(dialog WIN32 dialog.c dialog_res.rc)
target_link_libraries(dialog comctl32)
