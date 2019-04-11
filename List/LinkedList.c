//
// Created by ys on 2019/4/7.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"



//���õ�����
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

//���Ե�����ı���ϲ�

void testMerge()
{
    LinkedList La, Lb, Lc;
    ElemType arr1[20] = {1,3,5,7,9,100};
    ElemType arr2[20] = {4,8,12,25,90};
    LinkedListCreate2(&La, arr1, 6);
    LinkedListCreate2(&Lb, arr2, 5);
    //�ϲ�֮ǰ��La�� Lb
    puts("�ϲ�֮ǰ");
    LinkedListTravel(La);
    LinkedListTravel(Lb);
    LinkedListMerge(&La, &Lb, &Lc);
    puts("�ϲ�֮��");
    LinkedListTravel(La);
    LinkedListTravel(Lb);

}

//���Ե�����
void testLinkedList()
{
    LinkedList La, Lb;
    ElemType arr[5] = {1,2};
    ElemType arr1[6] = {6,7,8};
    LNode *pa, *pb;
    LinkedListCreate1(&La, arr, 5);
    LinkedListCreate2(&Lb, arr1, 6);
    printf("����La�ĳ���Ϊ%d\n", LinkedListLength(La));
    printf("����Lb�ĳ���Ϊ%d\n", LinkedListLength(Lb));
    pa = LinkedListGet(La, 3);
    pb = LinkedListGet(Lb, 4);
    printf("����La�ĵ�3��Ԫ��Ϊ%d\n", pa->data);
    printf("����Lb�ĵ�3��Ԫ��Ϊ%d\n", pb->data);
    LinkedListTravel(La);
    LinkedListTravel(Lb);


    puts("������������������La������Ԫ�ؽ��в���");
    pa = LinkedListGet(La, 3);
    LinkedListInsert(La, pa, 900);
    puts("�������֮��La������Ԫ��Ϊ��");
    LinkedListTravel(La);

    puts("������������������La��5��Ԫ�ؽ��в���");
    pa = LinkedListGet(La, 5);
    LinkedListInsert(La, pa, 500);
    puts("�������֮��La������Ԫ��Ϊ��");
    LinkedListTravel(La);

    puts("������������������La��1��Ԫ�ؽ��в���");
    pa = LinkedListGet(La, 1);
    LinkedListInsert(La, pa, 100);
    puts("�������֮��La������Ԫ��Ϊ��");
    LinkedListTravel(La);


    printf("ɾ��La��һ��Ԫ��%d\n", pa->data);
    LinkedListDel(La, pa->data);
    puts("ɾ��֮���La��");
    LinkedListTravel(La);
    printf("ɾ��La��һ��Ԫ��%d\n", 5);
    LinkedListDel(La, 5);
    puts("ɾ��֮���La��");
    LinkedListTravel(La);
    printf("ɾ��La��һ��Ԫ��%d\n", 900);
    LinkedListDel(La, 900);
    puts("ɾ��֮���La��");
    LinkedListTravel(La);

}



void LinkedListTravel(LinkedList L)
{
    LNode *p;
    if(L==NULL){
        exit(0);
    }
    p = L->next;
    //puts("��ʼ��������");
    while (p!=NULL )
    {
        printf("(%d)->",p->data);
        p = p->next;
    }
    printf("NULL\n");
    //puts("�����������");
}

//�����ʼ��
void LinkedListInit(LinkedList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL)
    {
        printf("����ռ�ʧ��\n");
        exit(0);
    }
    (*L)->next == NULL;
}


//��������Ĳ���
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

//������ȡԪ��
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

//������λ����
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

//������������
void LinkedListInsert(LinkedList L, LNode *p, ElemType e) {
    LNode *q = (LNode *) malloc(sizeof(LNode));
    if (q == NULL) {
        printf("����ռ�ʧ��!\n");
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

//��ͷ����ɾ������
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

//ͷ�巨����������
void LinkedListCreate1(LinkedList *L, ElemType a[], int n)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL)
    {
        printf("����ռ�ʧ��\n");
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
//β�巨����������
void LinkedListCreate2(LinkedList *L, ElemType a[], int n)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if((*L)==NULL)
    {
        printf("����ռ�ʧ��\n");
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


//��ͷ���ĵ�������ϲ�����
void LinkedListMerge(LinkedList *La, LinkedList *Lb, LinkedList *Lc)
{
    LNode *pa = (*La)->next;
    LNode *pb = (*Lb)->next;
    *Lc = *La;
    LNode *pc = *Lc;
    //����������Ƚ�
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