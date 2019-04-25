cmake_minimum_required(VERSION 3.10)
project(datastruct C)
set(CMAKE_C_STANDARD 99)



add_executable(dataStruct main.c tools.c tools.h Tree/BinTree.c Tree/BinTree.h Tree/HFTree.c Tree/HFTree.h Graph/AdjGraph.c Graph/AdjGraph.h Graph/AdjLinkedList.c Graph/AdjLinkedList.h Search/LinklistSearch.c Search/LinklistSearch.h Sort/InsertSort.c Sort/InsertSort.h)