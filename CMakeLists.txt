cmake_minimum_required(VERSION 3.31)
project(TREE)

set(CMAKE_CXX_STANDARD 20)

add_executable(TREE main.cpp
        header_files/tree.h
        source_files/tree.cpp
        source_files/file.cpp
        header_files/file.h
)
