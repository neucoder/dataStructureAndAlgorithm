//
// Created by ys on 2019/4/25.
//
#ifndef DATASTRUCT_INSERTSORT_C
#define DATASTRUCT_INSERTSORT_C


#include "InsertSort.h"
#include "../tools.h"

//直接插入排序，插入操作
void straipass(ElemType *SqList, ElemType key, int len)
{
    SqList[0] = key;
    int pos = len;
    while (key < SqList[pos])
    {
        SqList[pos+1] = SqList[pos];
        pos--;
    }
    SqList[pos+1] = key;
}
//直接插入排序
void straiSort(ElemType *SqList, int len)
{
    for (int i = 2; i < len+1; ++i) {
        straipass(SqList, SqList[i], i - 1);
    }
}
void bstraipass(ElemType *SqList, ElemType key, int len)
{
    SqList[0] = key;
    int low = 1, high = len;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(SqList[mid] < key)
        {
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }

    for (int i = len ; i > high + 1; --i) {
        SqList[i+1] = SqList[i];
    }
    SqList[high+1] = key;

}
//折半插入排序
void binInsertSort(ElemType *SqList, int len)
{
    for (int i = 2; i < len+1; ++i) {
        bstraipass(SqList, SqList[i], i - 1);
    }
}

//二路插入排序
void twoSort(ElemType *SqList, int len);

//希尔排序

void shellSort(ElemType *SqList, int len);

void testSort()
{
    int start,end;
    const int N = 100*1024;
    ElemType * SqList = (int *)malloc(sizeof(int)*(N + 1));
    for (int i = 1; i <= N; ++i) {
        SqList[i] = randint(0, 2 * N);
    }
    printf("%d,%d,%d",SqList[1],SqList[2],SqList[3]);
    char *fname = "../data/unsort.txt";
    char *fSortname = "../data/sort.txt";

    printToFile(fname, SqList, N);


    start = clock();
    binInsertSort(SqList, N);
    end = clock();
    printf("排序用时:%dms\n", end - start);

    printToFile(fSortname, SqList, N);
    free(SqList);
}


#endif //DATASTRUCT_INSERTSORT_H