#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"


//初始化
void SeqListInit(SeqList *L) {
    L->length = 0;
}

//求长度
int SeqListLength(SeqList L) {
    return L.length;
}

//取元素
ElemType SeqListGet(SeqList L, int i) {
    if ((i >= 1) && (i <= L.length)) {
        return L.data[i - 1];
    } else {
        printf("i值不合法\n");
        exit(0);
    }
}

//定位操作
int SeqlistLocate(SeqList L, ElemType e) {
    int i = 0;
    while ((i <= L.length) && (e != L.data[i])) {
        i++;
    }

    if (i <= L.length) {
        return i+1;
    } else {
        printf("此元素不在表中\n");
        return 0;
    }
}


//求前驱操作
ElemType SeqListPrior(SeqList L, ElemType e) {
    int i = SeqlistLocate(L, e);
    if (1 == i) {
        printf("第一个元素没有前驱\n");
        exit(0);
    } else {
        return L.data[i - 2];
    }
}

//求后继操作
ElemType SeqListNext(SeqList L, ElemType e) {
    int i = SeqlistLocate(L, e);
    if (L.length == i) {
        printf("最后一个元素没有后继\n");
        exit(0);
    } else {
        return L.data[i];
    }
}

//前插操作
void SeqListInsert(SeqList *L, int i, ElemType b) {
    if (L->length == MAXSIZE) {
        printf("表已满，无法进行插入操作\n");
        exit(0);
    }
    if ((i < 1) || (i > L->length + 1)) {
        printf("i值不合法\n");
        exit(0);
    }
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];

    }

    L->data[i - 1] = b;
    L->length++;
}

//删除 操作
void SeqListDel(SeqList *L, int i) {
    if ((i < 1) || (i > L->length)) {
        printf("i值不合法\n");
        exit(0);
    }
    for (int j = i; j <= L->length - 1; j++) {
        L->data[j - 1] = L->data[j];
    }

    L->length--;

}

//判空操作
int SeqListEmpty(SeqList L) {
    return !L.length;
}

//遍历操作
void SeqListTravel(SeqList L) {
    printf("-------------------------------------------\n");
    if (SeqListEmpty(L)) {
        printf("这是一个空表\n");
    } else {
        for (int i = 1; i <= L.length; ++i) {
            printf("第%d个元素是%d\n", i, L.data[i - 1]);
        }
    }
}

//线性表的保序合并
void ListMerge(SeqList *La, SeqList *Lb, SeqList *Lc) {
    SeqListInit(Lc);
    int i = 1;
    int j = 1;
    int k = 0;
    while ((i <= SeqListLength(*La)) && (j <= SeqListLength(*Lb))) {

        if (SeqListGet(*La, i) <= SeqListGet(*Lb, j)) {

            SeqListInsert(Lc, k + 1, SeqListGet(*La, i));
            k++;
            i++;

        } else {

            SeqListInsert(Lc, k + 1, SeqListGet(*Lb, j));
            k++;
            j++;
        }
    }
    while (i <= SeqListLength(*La)) {

        SeqListInsert(Lc, k + 1, SeqListGet(*La, i));
        k++;
        i++;
    }

    while (j <= SeqListLength(*Lb)) {

        SeqListInsert(Lc, k + 1, SeqListGet(*Lb, j));
        k++;
        j++;
    }

}
void ListUnion(SeqList* La, SeqList* Lb)
{
    int n = SeqListLength(*La);
    for (int i = 1; i <= SeqListLength(*Lb); ++i) {
        ElemType x = SeqListGet(*Lb, i);
        if(SeqlistLocate(*La, x)==0)
        {
            SeqListInsert(La, n+1, x);
            n++;
        }
    }
}

//表排序
void SeqListSort(SeqList *L) {
    for (int i = 0; i < L->length - 1; ++i) {
        for (int j = i + 1; j < L->length; ++j) {
            if (L->data[i] > L->data[j]) {
                ElemType tmp;
                tmp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = tmp;
            }
        }
    }
}



