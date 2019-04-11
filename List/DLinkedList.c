//
// Created by ys on 2019/4/10.
//

#include <stdlib.h>
#include <stdio.h>
#include "DLinkedList.h"
#include "../tools.h"

//遍历操作
void DLinkedListTravel(DLinkedList L)
{
    DLnode *p = L->next;
    while (p!=NULL)
    {
        printf("(%d)->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}


//获取第i个元素
DLnode *DLinkedListGet(DLinkedList L, int i)
{
    int j = 1;
    DLnode *p;
    if(i < 1)
    {
        printf("不合法元素的获取\n");
        p = NULL;
        return p;
    }
    p = L->next;

    while ((j < i) && p!=NULL)
    {
        p = p->next;
        j++;
    }

    return p;
}

//插入操作
void DLinkedListInsert(DLinkedList L, ElemType e, DLnode *p) {
    if(p==NULL)
    {
        printf("不合法的插入操作，p=NULL\n");
        exit(0);
    }
    DLnode *q = (DLnode *)malloc(sizeof(DLnode));
    q->data = e;
    q->next = p;
    q->prior = p->prior;
    p->prior->next=q;
    p->prior = q;
}

//删除操作
void DLinkedListDel(DLinkedList L, ElemType e) {
    DLnode *p = L->next;
    while ((p!=NULL)&&(p->data!=e))
    {
        p = p->next;
    }
    if(p==NULL)
    {
        printf("此元素不在表中无法执行删除操作\n");
        exit(0);
    }
    DLnode *q = p->prior;
    q->next = p->next;
    if(p->next!=NULL)
    {
        p->next->prior=q;
    }
    free(p);
    p=NULL;
}

//创建双链表
void DLinkedListCreate(DLinkedList *L, ElemType a[], int n) {
    DLnode *tail, *p;
    (*L) = (DLnode *) malloc(sizeof(DLnode));
    if (*L == NULL) {
        printf("空间申请失败\n");
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    tail = (*L);
    for (int i = 0; i < n; ++i) {
        p = (DLnode *)malloc(sizeof(DLnode));
        p->data = a[i];
        p->next = NULL;
        tail->next = p;
        p->prior = tail;
        tail = p;
    }
}

void Del(DLinkedList L, ElemType e)
{
    DLnode *p = L->next;
    while ((p!=NULL)&&(p->data!=e))
    {
        p=p->next;
    }

    if(p!=NULL)
    {
        p->prior->next=p->next;
        p->next->prior=p->prior;
    }
    free(p);
}

void testInsertAndDel()
{
    ElemType a[10], b[10]={1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; ++i) {
        a[i] = randint(1,100);
    }
    DLinkedList L1=NULL, L2;
    DLinkedListCreate(&L1, a, 10);
    DLinkedListCreate(&L2, b, 10);
    DLnode *p;
    /*
    for (int j = 0; j < 10; ++j) {
        printf("插入之前\n");
        DLinkedListTravel(L1);
        p = DLinkedListGet(L1,j+1);
        DLinkedListInsert(L1, j*j*j, p);
        printf("插入之后\n");
        DLinkedListTravel(L1);
    }*/

        DLinkedListTravel(L2);
        DLinkedListDel(L2, 10);
        DLinkedListTravel(L2);




}

//双链表创建测试
void testDlinkedListCreate()
{
    DLinkedList L1, L2, L3, L4;
    ElemType a1[1] = {1};
    ElemType a2[2] = {1,2};
    ElemType a3[7] = {1,2,3,4,5,6,7};
    ElemType a4[20];
    for (int i = 0; i < 20; ++i) {
        a4[i] = randint(1, 100);

    }
    DLinkedListCreate(&L1, a1, 1);
    DLinkedListCreate(&L2, a2, 2);
    DLinkedListCreate(&L3, a3, 7);
    DLnode *p;
    for (int j = -1; j < 10; ++j) {
        p = DLinkedListGet(L3, j);
        if(p==NULL)
        {
            printf("%d不合法的元素\n", j);
        } else
        {
            printf("获取的第%d个元素为%d\n", j, p->data);
        }

    }
    DLinkedListCreate(&L4, a4, 20);
    DLinkedListTravel(L3);


}
