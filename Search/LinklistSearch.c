//
// Created by ys on 2019/4/23.
//

#include "LinklistSearch.h"
#include "../tools.h"

//线性查找元素
int SqListSearch(ElemType *SqList, int key, int len) {
    SqList[0] = key;
    int i = -1;
    for (i = len; SqList[i] != key; --i);
    return i;
}

void testSqlistSearch() {
    const int N = 1000;
    ElemType *SqList = (ElemType *) malloc(sizeof(ElemType) * (N + 1));
    for (int i = 1; i <= N; ++i) {
        SqList[i] = randint(1, 10000);
    }

    ElemType key = 200;
    int i = SqListSearch(SqList, key, N);
    printf("%d\n", i);
    for (int i = 0; i <= N; ++i) {
        printf("%8d", SqList[i]);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    free(SqList);
    SqList = NULL;

}

//折半查找
int BinSearch(ElemType *SqList, ElemType key, int low, int high) {
    int mid = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if(SqList[mid] == key)
        {
            return mid;
        }
        if(SqList[mid] > key)
        {
            high = mid - 1;
        } else
        {
            low = mid + 1;
        }
    }

    return -1;
}

//折半查找递归算法
int RBinSearch(ElemType *SqList, int key, int low, int high)
{
    if(low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if(SqList[mid] == key)
    {
        return mid;
    }

    if(SqList[mid] > key)
    {
        RBinSearch(SqList, key, low, mid - 1);
    } else
    {
        RBinSearch(SqList, key, mid + 1, high);
    }

}

void testBSearch()
{
    const int N = 1001;
    int *List = (int *)malloc(1001 * sizeof(int));
    for (int i = 1; i < N; ++i) {
        List[i] = i;
    }
    int key = 74;

    int index = BinSearch(List, key, 1, N-1);

    printf("查找的index为:%d\n", index);
    index = RBinSearch(List, key, 1, N-1);
    printf("递归查找的index为:%d\n", index);

    free(List);
    List = NULL;
}








