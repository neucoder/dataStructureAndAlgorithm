cmake_minimum_required(VERSION 3.10)
project(datastruct C)

set(CMAKE_C_STANDARD 99)

add_executable(dataStruct main.c tools.c tools.h List/LinkedList.c List/LinkedList.h)