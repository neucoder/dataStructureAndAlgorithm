//
// Created by ys on 2019/4/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Tree/BinTree.h"
#include "Tree/HFTree.h"
#include "Graph/AdjLinkedList.h"
#include "Graph/AdjGraph.h"
#include "Sort/InsertSort.h"
#include "Search/LinklistSearch.h"





#ifndef DATASTRUCT_TOOLS_H
#define DATASTRUCT_TOOLS_H
#define true 1
#define false 0
void testFp();


#ifndef DEBUG
#define DEBUG

void printDebug();


#endif


/*
//��ʱ��
int start = clock();
for (int i = 0; i < 1102111100; ++i) {

}
int end = clock();

 */
//����һ��������� ��ΧminVal-maxVal
int randint(int minVal, int maxVal);

//����ָ�����
void swap(int **a, int **b);
//���Խ���ָ������
void testSwap();

void readFile();

//��ȡ�ļ�������
void readData();
//ð������
void bubbleSort(int a[], int n);


void printToFile(char *fname, ElemType *arr, int arrLen);

void testRand();


void printArr(ElemType *arr, int len);

#endif //DATASTRUCT_TOOLS_H
