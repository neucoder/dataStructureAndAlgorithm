//
// Created by ys on 2019/4/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef DATASTRUCT_TOOLS_H
#define DATASTRUCT_TOOLS_H
#define true 1
#define false 0


/*
//计时用
int start = clock();
for (int i = 0; i < 1102111100; ++i) {

}
int end = clock();

 */
//产生一个随机整数 范围minVal-maxVal
int randint(int minVal, int maxVal);

//交换指针变量
void swap(int **a, int **b);
//测试交换指针表变量
void testSwap();

void readFile();

//读取文件的数据
void readData();
//冒泡排序
void bubbleSort(int a[], int n);

#endif //DATASTRUCT_TOOLS_H
