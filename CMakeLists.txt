cmake_minimum_required(VERSION 3.26)
project(DA_Proj_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA_Proj_2
        main.cpp
        src/Graph.h
        src/Graph.cpp
        src/FileManager.h
        src/FileManager.cpp
        src/Graph.cpp
        src/app.cpp
        src/UFDS.cpp
        src/app.h)

