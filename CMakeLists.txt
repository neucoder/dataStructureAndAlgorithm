cmake_minimum_required(VERSION 3.10)
project(datastruct C)
set(CMAKE_C_STANDARD 99)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()


add_executable(dataStruct main.c tools.c tools.h Tree/BinTree.c Tree/BinTree.h Tree/HFTree.c Tree/HFTree.h Graph/AdjGraph.c Graph/AdjGraph.h Graph/AdjLinkedList.c Graph/AdjLinkedList.h Search/LinklistSearch.c Search/LinklistSearch.h Sort/InsertSort.c Sort/InsertSort.h)