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

//选择排序
void selectSort(ElemType *SqList, int len)
{
    int min;
    for (int i = 1; i < len; ++i) {
        min = i;
        for (int j = i+1; j <= len; ++j) {
            if(SqList[min] > SqList[j])
            {
                min = j;
            }
        }
        swap(&SqList[i], &SqList[min]);
    }
}

//调整为大顶堆
//依次调整使堆为一个数据构成大顶堆
void heapAdjust(ElemType *SqList, int s, int m)
{

    ElemType tmp;
    tmp = SqList[s];
    for (int i = 2 * s; i <= m; i*=2) {
        if(i < m && SqList[i] < SqList[i+1])
        {
            ++i;
        }

        if(tmp >= SqList[i])
        {
            break;
        }

        SqList[s] = SqList[i];
        s = i;
    }
    SqList[s] = tmp;
}

//堆排序
void HeapSort(ElemType *SqList, int len)
{
    int i;
    for (i = len/2; i > 0; --i) {
        heapAdjust(SqList, i, len);
    }

    for ( i = len; i > 1; --i) {
        swap(&SqList[1], &SqList[i]);
        heapAdjust(SqList, 1, i-1);
    }
}

void timeOfSort(char *dataFile, void (*fun)(ElemType *Sqlist, int len), char *funName, ElemType *SqList, int N)
{
    int start, end;
    readFromFile(dataFile, SqList, N);
    start = clock();
    fun(SqList, N);
    end = clock();
    printf("%s排序用时:%dms\n",funName, end - start);
}


void arrEqual(ElemType *arr1, ElemType *arr2, int s, int N)
{
    for (int i = s; i <= N ; ++i) {
        if(arr1[i]!=arr2[i])
        {
            printf("%d: arr1: %d  arr2: %d\n",i,arr1[i],arr2[i]);
        }
    }

}


void mergeSort(ElemType *SqList, int len)
{
    ElemType *tmpArr = (ElemType *)malloc((len+1)* sizeof(ElemType));
    mSort(SqList, tmpArr, 1, len);
}
//递归合并排序
void mSort(ElemType *A, ElemType *tmpArr, int left, int right)
{
    int center;
    if(left < right)
    {
        center = (left + right) / 2;
        mSort(A, tmpArr, left, center);
        mSort(A, tmpArr, center + 1, right);
        merge(A, tmpArr, left, center, right);
    }
}
//两数组合并
void merge(ElemType *A, ElemType *tmpArr, int left, int center, int right)
{
    int i, j, tmp;
    i = left;
    j = center + 1;
    tmp = 1;
    while (i <= center && j <= right)
    {
        tmpArr[tmp++] = A[i] < A[j] ? A[i ++] : A[j ++];

    }
    while (i <= center )
    {
        tmpArr[tmp++] = A[i++];

    }
    while (j <= right)
    {
        tmpArr[tmp++] = A[j++];
    }
    i = right;
    tmp--;
    while (tmp > 0)
    {
        A[i--] = tmpArr[tmp--];

    }
}


void testSort() {
    int start, end;
    const int N = 100 * 1024;

    int a[3] = {-1 ,200,90};
    int t[3];
    merge(a,t,1,1,2);
    printArr(a, 2);
    /*
    ElemType *SqList = (int *) malloc(sizeof(int) * (N + 1));
    ElemType *SqList1 = (int *) malloc(sizeof(int) * (N + 1));

    free(SqList1);
    free(SqList);
*/
}


#endif //DATASTRUCT_INSERTSORT_H