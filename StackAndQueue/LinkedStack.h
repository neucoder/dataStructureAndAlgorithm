//
// Created by ys on 2019/4/11.
//

#ifndef DATASTRUCT_LINKEDSTACK_H
#define DATASTRUCT_LINKEDSTACK_H
#define ElemType int
//��������
struct Node
{
    ElemType data;
    struct Node *next;
};
typedef struct Node LStackNode;
typedef struct
{
    LStackNode *top;
} LinkedStack;

//��ʼ��
void Init(LinkedStack **S);
//�пղ���
int Empty(LinkedStack *S);
//��ջ����
void Push(LinkedStack *S, ElemType x);
//��ջ����
ElemType Pop(LinkedStack *S);
//��ȡջ��Ԫ��
ElemType Get(LinkedStack *S);

//����
void testLinkedList();
#endif //DATASTRUCT_LINKEDSTACK_H
