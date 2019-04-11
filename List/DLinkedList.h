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



//����ɾ���Ͳ������
void testInsertAndDel();


void Del(DLinkedList L, ElemType e);

//��ȡ��i��Ԫ��
DLnode *DLinkedListGet(DLinkedList L, int i);
//��������
void DLinkedListTravel(DLinkedList L);


//�������
void DLinkedListInsert(DLinkedList L, ElemType e, DLnode *p);
//ɾ������
void DLinkedListDel(DLinkedList L, ElemType e);

//����˫����
void DLinkedListCreate(DLinkedList *L, ElemType a[], int n);

//˫����������
void testDlinkedListCreate();
#endif //DATASTRUCT_DLINKEDLIST_H
