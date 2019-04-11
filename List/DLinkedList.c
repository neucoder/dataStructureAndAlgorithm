//
// Created by ys on 2019/4/10.
//

#include <stdlib.h>
#include <stdio.h>
#include "DLinkedList.h"
#include "../tools.h"

//��������
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


//��ȡ��i��Ԫ��
DLnode *DLinkedListGet(DLinkedList L, int i)
{
    int j = 1;
    DLnode *p;
    if(i < 1)
    {
        printf("���Ϸ�Ԫ�صĻ�ȡ\n");
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

//�������
void DLinkedListInsert(DLinkedList L, ElemType e, DLnode *p) {
    if(p==NULL)
    {
        printf("���Ϸ��Ĳ��������p=NULL\n");
        exit(0);
    }
    DLnode *q = (DLnode *)malloc(sizeof(DLnode));
    q->data = e;
    q->next = p;
    q->prior = p->prior;
    p->prior->next=q;
    p->prior = q;
}

//ɾ������
void DLinkedListDel(DLinkedList L, ElemType e) {
    DLnode *p = L->next;
    while ((p!=NULL)&&(p->data!=e))
    {
        p = p->next;
    }
    if(p==NULL)
    {
        printf("��Ԫ�ز��ڱ����޷�ִ��ɾ������\n");
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

//����˫����
void DLinkedListCreate(DLinkedList *L, ElemType a[], int n) {
    DLnode *tail, *p;
    (*L) = (DLnode *) malloc(sizeof(DLnode));
    if (*L == NULL) {
        printf("�ռ�����ʧ��\n");
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
        printf("����֮ǰ\n");
        DLinkedListTravel(L1);
        p = DLinkedListGet(L1,j+1);
        DLinkedListInsert(L1, j*j*j, p);
        printf("����֮��\n");
        DLinkedListTravel(L1);
    }*/

        DLinkedListTravel(L2);
        DLinkedListDel(L2, 10);
        DLinkedListTravel(L2);




}

//˫����������
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
            printf("%d���Ϸ���Ԫ��\n", j);
        } else
        {
            printf("��ȡ�ĵ�%d��Ԫ��Ϊ%d\n", j, p->data);
        }

    }
    DLinkedListCreate(&L4, a4, 20);
    DLinkedListTravel(L3);


}
