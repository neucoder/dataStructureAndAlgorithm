//
// Created by ys on 2019/4/25.
//
#ifndef DATASTRUCT_INSERTSORT_C
#define DATASTRUCT_INSERTSORT_C


#include "InsertSort.h"
#include "../tools.h"

//直接插入排序，插入操作
void straipass(ElemType *SqList, ElemType key, int len) {
    SqList[0] = key;
    int pos = len;
    while (key < SqList[pos]) {
        SqList[pos + 1] = SqList[pos];
        pos--;
    }
    SqList[pos + 1] = key;
}


//直接插入排序
void straiSort(ElemType *SqList, int len) {
    for (int i = 2; i < len + 1; ++i) {
        straipass(SqList, SqList[i], i - 1);
    }
}


void bstraipass(ElemType *SqList, ElemType key, int len) {
    SqList[0] = key;
    int low = 1, high = len;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < SqList[mid]) {
            high = mid - 1;

        } else {
            low = mid + 1;
        }
    }

    for (int i = len; i > high; --i) {
        SqList[i + 1] = SqList[i];
    }
    SqList[high + 1] = key;

}

//折半插入排序
void binInsertSort(ElemType *SqList, int len) {
    for (int i = 2; i <= len; ++i) {
        bstraipass(SqList, SqList[i], i-1);
    }
}

//二路插入排序
void twoSort(ElemType *SqList, int len);

//希尔排序


void shellSort(ElemType *SqList, int len) {

    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap + 1; i <= len; i += 1) {
            SqList[0] = SqList[i];
            int j;
            for (j = i; j > gap && SqList[j - gap] > SqList[0]; j -= gap) {
                SqList[j] = SqList[j - gap];
            }
            SqList[j] = SqList[0];
        }
    }
}


void bubbleSort1(ElemType *SqList, int len) {
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j < len - i + 1; ++j) {
            if (SqList[j] > SqList[j + 1]) {
                SqList[0] = SqList[j];
                SqList[j] = SqList[j + 1];
                SqList[j + 1] = SqList[0];
            }
        }
    }
}

void testSort() {
    int start, end;
    const int N = 100 * 1024;
    ElemType *SqList = (int *) malloc(sizeof(int) * (N + 1));
    ElemType *SqList1 = (int *) malloc(sizeof(int) * (N + 1));
    ElemType *SqList2 = (int *) malloc(sizeof(int) * (N + 1));
//    readFromFile("raw.txt", SqList, N);
//    bubbleSort1(SqList, N);
//
//    readFromFile("raw.txt", SqList1, N);
//    binInsertSort(SqList1, N);
//
//    readFromFile("raw.txt", SqList2, N);
//    shellSort(SqList2, N);
//    for (int i = 1; i <= N; ++i) {
//        printf("%8d %8d %8d\n",SqList[i], SqList1[i], SqList2[i]);
//        if(SqList[i]!=SqList1[i])
//        {
//            printf("bubble != binsort %d\n", i);
//        }
//
//        if(SqList[i]!=SqList2[i])
//        {
//            printf("bubble != sheelsort %d\n", i);
//        }
 //   }

//    readFromFile("raw.txt", SqList, N);
//    start = clock();
//    bubbleSort1(SqList, N);
//    end = clock();
//    printf("bubble排序用时:%dms\n", end - start);
//    for (int i = 1; i <= N; ++i) {
//        printf("%8d",SqList[i]);
//        if(i%10==0)
//            putchar('\n');
//    }
    //printToFile("bubble.txt", SqList, N);


//    for (int i = 1; i <= N; ++i) {
//        SqList[i] = randint(0, 2 * N);
//    }


    //printToFile("raw.txt", SqList, N);
//    readFromFile("raw.txt", SqList, N);
//    start = clock();
//    shellSort(SqList, N);
//    end = clock();
//    printf("shell排序用时:%dms\n", end - start);
//    printToFile("shell.txt", SqList, N);
//
//
//
//    readFromFile("raw.txt", SqList, N);
//    start = clock();
//    straiSort(SqList, N);
//    end = clock();
//    printf("stra排序用时:%dms\n", end - start);
//    printToFile("straInsert.txt",SqList, N);
//
//
    readFromFile("raw.txt", SqList, N);
    start = clock();
    binInsertSort(SqList, N);
    end = clock();
    printf("binsort排序用时:%dms\n", end - start);
    printToFile("binInsert.txt",SqList, N);

//    readFromFile("raw.txt", SqList, N);
//    start = clock();
//    bubbleSort1(SqList, N);
//    end = clock();
//    printf("bubble排序用时:%dms\n", end - start);
//    printToFile("bubble.txt",SqList, N);


    free(SqList);
}


#endif //DATASTRUCT_INSERTSORT_H