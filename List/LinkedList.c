//
// Created by ys on 2019/4/7.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"



//逆置单链表
void LinkedListReverse(LinkedList *L)
{
    LinkedList p, q;
    if((*L)->next&&(*L)->next->next)
    {
        p = (*L)->next;
        q = p->next;
        (*L)->next=NULL;
        while (q)
        {
            p->next = (*L)->next;
            (*L)->next=p;
            p=q;
            q=q->next;

        }
        p->next = (*L)->next;
        (*L)->next=p;
    }
}

//测试单链表的保序合并

void testMerge()
{
    LinkedList La, Lb, Lc;
    ElemType arr1[20] = {1,3,5,7,9,100};
    ElemType arr2[20] = {4,8,12,25,90};
    LinkedListCreate2(&La, arr1, 6);
    LinkedListCreate2(&Lb, arr2, 5);
    //合并之前的La， Lb
    puts("合并之前");
    LinkedListTravel(La);
    LinkedListTravel(Lb);
    LinkedListMerge(&La, &Lb, &Lc);
    puts("合并之后");
    LinkedListTravel(La);
    LinkedListTravel(Lb);

}

//测试单链表
void testLinkedList()
{
    LinkedList La, Lb;
    ElemType arr[5] = {1,2};
    ElemType arr1[6] = {6,7,8};
    LNode *pa, *pb;
    LinkedListCreate1(&La, arr, 5);
    LinkedListCreate2(&Lb, arr1, 6);
    printf("链表La的长度为%d\n", LinkedListLength(La));
    printf("链表Lb的长度为%d\n", LinkedListLength(Lb));
    pa = LinkedListGet(La, 3);
    pb = LinkedListGet(Lb, 4);
    printf("链表La的第3个元素为%d\n", pa->data);
    printf("链表Lb的第3个元素为%d\n", pb->data);
    LinkedListTravel(La);
    LinkedListTravel(Lb);


    puts("链表插入操作，对链表La第三个元素进行插入");
    pa = LinkedListGet(La, 3);
    LinkedListInsert(La, pa, 900);
    puts("链表插入之后，La的所有元素为：");
    LinkedListTravel(La);

    puts("链表插入操作，对链表La第5个元素进行插入");
    pa = LinkedListGet(La, 5);
    LinkedListInsert(La, pa, 500);
    puts("链表插入之后，La的所有元素为：");
    LinkedListTravel(La);

    puts("链表插入操作，对链表La第1个元素进行插入");
    pa = LinkedListGet(La, 1);
    LinkedListInsert(La, pa, 100);
    puts("链表插入之后，La的所有元素为：");
    LinkedListTravel(La);


    printf("删除La的一个元素%d\n", pa->data);
    LinkedListDel(La, pa->data);
    puts("删除之后的La：");
    LinkedListTravel(La);
    printf("删除La的一个元素%d\n", 5);
    LinkedListDel(La, 5);
    puts("删除之后的La：");
    LinkedListTravel(La);
    printf("删除La的一个元素%d\n", 900);
    LinkedListDel(La, 900);
    puts("删除之后的La：");
    LinkedListTravel(La);

}



void LinkedListTravel(LinkedList L)
{
    LNode *p;
    if(L==NULL){
        exit(0);
    }
    p = L->next;
    //puts("开始遍历链表");
    while (p!=NULL )
    {
        printf("(%d)->",p->data);
        p = p->next;
    }
    printf("NULL\n");
    //puts("链表遍历结束");
}

//链表初始化
void LinkedListInit(LinkedList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL)
    {
        printf("申请空间失败\n");
        exit(0);
    }
    (*L)->next == NULL;
}


//链表求表长的操作
int LinkedListLength(LinkedList L)
{
    LNode *p;
    p = L->next;
    int j = 0;
    while (p!=NULL)
    {
        j++;
        p = p->next;
    }
    return j;
}

//单链表取元素
LinkedList LinkedListGet(LinkedList L, int i)
{
    LNode *p;
    p = L->next;
    int j = 1;
    while ((p!=NULL)&&(j<i))
    {
        p = p->next;
        j++;
    }
    return p;
}

//单链表定位操作
LNode *LinkedListLocate(LinkedList L, ElemType e)
{
    LNode *p = L->next;
    //int j = 1;
    while ((p!=NULL) && (p->data!=e))
    {
        p = p->next;
    }

    return p;
}

//单链表插入操作
void LinkedListInsert(LinkedList L, LNode *p, ElemType e) {
    LNode *q = (LNode *) malloc(sizeof(LNode));
    if (q == NULL) {
        printf("申请空间失败!\n");
        exit(0);
    }

    q->data = e;
    LNode *pre = L;
    while ((pre != NULL) && (pre->next != p))
    {
        pre = pre->next;
    }

    q->next = pre->next;
    pre->next = q;
}

//带头结点的删除操作
void LinkedListDel(LinkedList L, ElemType e)
{
    LNode *pre = L;
    while ((pre->next!=NULL)&&(pre->next->data!=e))
    {
        pre = pre->next;
    }

    LNode *p = pre->next;
    if(p!=NULL)
    {
        pre->next = p->next;
        free(p);
    }
}

//头插法创建单链表
void LinkedListCreate1(LinkedList *L, ElemType a[], int n)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL)
    {
        printf("申请空间失败\n");
        exit(0);
    }

    (*L)->next = NULL;
    LNode *p;
    for (int i = 0; i < n; ++i) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = a[i];
        p->next = (*L)->next;
        (*L)->next = p;

    }
    (*L)->next = p;

}
//尾插法创建单链表
void LinkedListCreate2(LinkedList *L, ElemType a[], int n)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if((*L)==NULL)
    {
        printf("申请空间失败\n");
        exit(0);
    }
    (*L)->next = NULL;
    LNode *tail = *L, *p;
    for (int i = 0; i < n; ++i) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = a[i];
        p->next=NULL;
        tail->next = p;
        tail = p;
    }

}


//带头结点的单链表保序合并操作
void LinkedListMerge(LinkedList *La, LinkedList *Lb, LinkedList *Lc)
{
    LNode *pa = (*La)->next;
    LNode *pb = (*Lb)->next;
    *Lc = *La;
    LNode *pc = *Lc;
    //两个链表结点比较
    while ((pa!=NULL)&&(pb!=NULL))
    {
        if(pa->data<=pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    if(pa!=NULL)
    {
        pc->next = pa;
    } else
    {
        pc->next = pb;
    }
    free(*Lb);
    *Lb = NULL;
}