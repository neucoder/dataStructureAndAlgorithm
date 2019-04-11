//
// Created by ys on 2019/4/10.
//

#ifndef DATASTRUCT_DLINKEDLIST_H
#define DATASTRUCT_DLINKEDLIST_H

#define ElemType int

struct Node
{
    ElemType data;
    struct Node *next, *prior;

};

typedef struct Node DLnode;
typedef struct Node *DLinkedList;



//测试删除和插入操作
void testInsertAndDel();


void Del(DLinkedList L, ElemType e);

//获取第i个元素
DLnode *DLinkedListGet(DLinkedList L, int i);
//遍历操作
void DLinkedListTravel(DLinkedList L);


//插入操作
void DLinkedListInsert(DLinkedList L, ElemType e, DLnode *p);
//删除操作
void DLinkedListDel(DLinkedList L, ElemType e);

//创建双链表
void DLinkedListCreate(DLinkedList *L, ElemType a[], int n);

//双链表创建测试
void testDlinkedListCreate();
#endif //DATASTRUCT_DLINKEDLIST_H
