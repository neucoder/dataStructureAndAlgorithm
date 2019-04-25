//
// Created by ys on 2019/4/25.
//

#ifndef DATASTRUCT_INSERTSORT_H
#define DATASTRUCT_INSERTSORT_H
#define ElemType int
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

void bstraipass(ElemType *SqList, ElemType key, int len);

void testSort();
#endif //DATASTRUCT_INSERTSORT_H
