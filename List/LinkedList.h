//
// Created by ys on 2019/4/7.
//

#ifndef DATASTRUCT_LINKEDLIST_H
#define DATASTRUCT_LINKEDLIST_H
#define ElemType int
//���ô�ͷ���

//�������㶨��
struct Node
{
    ElemType data;
    struct Node *next;

};

typedef struct Node LNode;
typedef struct Node *LinkedList;

//���Ե�����
void testLinkedList();
//�������

//�����ʼ��
void LinkedListInit(LinkedList *L);
//��������Ĳ���
int LinkedListLength(LinkedList L);
//������ȡԪ��
LinkedList LinkedListGet(LinkedList L, int i);
//������λ����
LNode *LinkedListLocate(LinkedList L, ElemType e);
//������������
void LinkedListInsert(LinkedList L, LNode *p, ElemType e);
//��ͷ����ɾ������
void LinkedListDel(LinkedList L, ElemType e);

//ͷ�巨����������
void LinkedListCreate1(LinkedList *L, ElemType a[], int n);
//β�巨����������
void LinkedListCreate2(LinkedList *L, ElemType a[], int n);

//��ͷ���ĵ�������ϲ�����
void LinkedListMerge(LinkedList *La, LinkedList *Lb, LinkedList *Lc);

#endif //DATASTRUCT_LINKEDLIST_H
