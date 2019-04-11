//
// Created by ys on 2019/4/7.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
//产生一个随机整数 范围minVal-maxVal

int randint(int minVal, int maxVal)
{
    int r;
    r = minVal + rand()%(maxVal - minVal + 1);
    return r;
}


//交换指针变量
void swap(int **a, int **b)
{
    int tmp;
    tmp = **a;
    **a = **b;
    **b = tmp;
}

//测试交换指针表变量
void testSwap()
{
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    *a = 3;
    *b = 5;
    printf("*a:%d and *b:%d\n", *a, *b);
    swap(&a, &b);
    printf("*a:%d and *b:%d\n", *a, *b);

}




