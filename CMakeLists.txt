cmake_minimum_required(VERSION 3.10)
project(datastruct C)

set(CMAKE_C_STANDARD 99)

add_executable(dataStruct main.c List/SeqList.h List/SeqList.c List/test.c tools.c tools.h)