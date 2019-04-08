//
// Created by ys on 2019/4/7.
//

#ifndef DATASTRUCT_LINKEDLIST_H
#define DATASTRUCT_LINKEDLIST_H
#define ElemType int
//采用带头结点

//单链表结点定义
struct Node
{
    ElemType data;
    struct Node *next;

};

typedef struct Node LNode;
typedef struct Node *LinkedList;

//测试单链表
void testLinkedList();
//链表遍历

//链表初始化
void LinkedListInit(LinkedList *L);
//链表求表长的操作
int LinkedListLength(LinkedList L);
//单链表取元素
LinkedList LinkedListGet(LinkedList L, int i);
//单链表定位操作
LNode *LinkedListLocate(LinkedList L, ElemType e);
//单链表插入操作
void LinkedListInsert(LinkedList L, LNode *p, ElemType e);
//带头结点的删除操作
void LinkedListDel(LinkedList L, ElemType e);

//头插法创建单链表
void LinkedListCreate1(LinkedList *L, ElemType a[], int n);
//尾插法创建单链表
void LinkedListCreate2(LinkedList *L, ElemType a[], int n);

//带头结点的单链表保序合并操作
void LinkedListMerge(LinkedList *La, LinkedList *Lb, LinkedList *Lc);

#endif //DATASTRUCT_LINKEDLIST_H
