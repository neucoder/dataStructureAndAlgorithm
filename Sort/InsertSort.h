//
// Created by ys on 2019/4/25.
//

#ifndef DATASTRUCT_INSERTSORT_H
#define DATASTRUCT_INSERTSORT_H
#define ElemType int


//快速排序获取中枢操作
int getPrivot(int *SqList, int left, int right);



void bubbleSort1(ElemType *SqList, int len);
//直接插入排序，插入操作
void straipass(ElemType *SqList, ElemType key, int len);
//直接插入排序
void straiSort(ElemType *SqList, int len);

//折半插入排序
void binInsertSort(ElemType *SqList, int len);

//二路插入排序
void twoSort(ElemType *SqList, int len);

//希尔排序

void shellSort(ElemType *SqList, int len);


//选择排序
void selectSort(ElemType *SqList, int len);

void bstraipass(ElemType *SqList, ElemType key, int len);

void testSort();
void timeOfSort(char *dataFile, void (*fun)(ElemType *Sqlist, int len), char *funName, ElemType *SqList, int N);

//调整为大顶堆
//依次调整使堆为一个数据构成大顶堆
void heapAdjust(ElemType *SqList, int s, int m);

//堆排序
void HeapSort(ElemType *SqList, int len);
void readFromFile(char *fname, ElemType * arr, int arrLen);


//二路归并排序

void mergeSort(ElemType *SqList, int len);
void mSort(ElemType *A, ElemType *tmparr, int left, int right);
void merge(ElemType *A, ElemType *tmparr, int left, int center, int right);


#endif //DATASTRUCT_INSERTSORT_H
