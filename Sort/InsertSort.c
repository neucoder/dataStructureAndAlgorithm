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
        bstraipass(SqList, SqList[i], i - 1);
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

//快速排序
//先获得枢纽元，采用的方法是三中值法
int getPrivot(int *SqList, int left, int right) {
    int center = (left + right) / 2;
    int _right = right;
    if (SqList[left] > SqList[center]) {
        swap(&SqList[left], &SqList[center]);
    }
    if (SqList[left] > SqList[right]) {
        swap(&SqList[left], &SqList[right]);
    }
    if (SqList[center] < SqList[right]) {
        swap(&SqList[center], &SqList[right]);
    }

    ElemType privotkey = SqList[right];

    while (left < right)
    {
        while (left < right && SqList[left] <= privotkey)
            left++;
        while (left < right && SqList[right] >= privotkey)
            right--;
        swap(&SqList[left], &SqList[right]);

    }
    swap(&SqList[left], &SqList[_right]);
    return left;
}

void insertSort(ElemType *SqList, int left, int right)
{

    for (int i = left + 1; i <= right; ++i) {
        int j;
        int key = SqList[i];
        for (j = left; j < i; ++j) {
            if(key < SqList[j])
            {
                break;
            }
        }

        for (int k = i; k > j; --k) {
            SqList[k] = SqList[k-1];
        }
        SqList[j] = key;
    }
}

//快速排序有错误排查完成，可以正常运行
void quickSort(ElemType *SqList, int left, int right) {
    int privot;
    if (right - left > 7) {
        privot = getPrivot(SqList, left, right);
        quickSort(SqList, left, privot-1);
        quickSort(SqList, privot+1,right);

    } else
    {
        insertSort(SqList, left, right);
    }
}


void testSort() {
    int start, end;
    const int N = 100 * 1024;
    ElemType *SqList = (int *) malloc(sizeof(int) * (N + 1));
    ElemType *SqList1 = (int *) malloc(sizeof(int) * (N + 1));

    readFromFile("raw.txt", SqList, N);
    start = clock();
    quickSort(SqList, 1, N);
    end = clock();
    printf("qsort排序用时:%dms\n", end - start);
    //printToFile("quick.txt", SqList, N);
    //printArr(SqList, N);


    readFromFile("raw.txt", SqList1, N);
    start = clock();
    shellSort(SqList1, N);
    end = clock();
    printf("shellsort排序用时:%dms\n", end - start);
    //printArr(SqList1, N);
    for (int i = 1; i <= N ; ++i) {
        if(SqList[i]!=SqList1[i])
        {
            printf("%d, quick:%d  shell: %d\n",i,SqList[i],SqList1[i]);
        }
    }
    //printToFile("shell.txt",SqList, N);

    free(SqList1);
    free(SqList);
}


#endif //DATASTRUCT_INSERTSORT_H