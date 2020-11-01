cmake_minimum_required(VERSION 3.10)

# # Set compilers and make tools.
# set(CMAKE_MAKE_PROGRAM mingw32-make.exe)
set(CMAKE_C_COMPILER "C:/Program Files (x86)/mingw64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/mingw64/mingw64/bin/g++.exe")

# CursedWindows makes heavy use of lambda expressions which were added in C++11, but expanded on in C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#
if (WIN32)
    set(CMAKE_MAKE_PROGRAM mingw32-make.exe)
endif (WIN32)


# set the project name
project(CursedWindows VERSION 0.1 DESCRIPTION "C++ UI library")

message("this is a test")
add_library(test SHARED file(GLOB src "*.h" "*.cpp"))

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY build/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/bin)
