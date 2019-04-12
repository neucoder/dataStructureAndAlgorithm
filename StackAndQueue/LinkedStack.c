//
// Created by ys on 2019/4/11.
//

#include "LinkedStack.h"
#include "../tools.h"

//��ʼ��
void Init(LinkedStack **S)
{
    (*S) = (LinkedStack *)malloc(sizeof(LinkedStack));
    (*S)->top = NULL;
}
//�пղ���
int Empty(LinkedStack *S)
{
    if(S->top == NULL)
    {
        return true;
    } else
    {
        return true;
    }
}
//��ջ����
void Push(LinkedStack *S, ElemType x)
{
    LStackNode *ls;
    ls = (LStackNode *)malloc(sizeof(LStackNode));
    if(ls == NULL)
    {
        printf("����ռ�ʧ��\n");
        exit(0);
    }
    ls->data = x;
    ls->next = S->top;
    S->top = ls;
}
//��ջ����
ElemType Pop(LinkedStack *S)
{
    LStackNode *p;
    ElemType x;
    if(S->top ==NULL)
    {
        printf("ջ�ղ��ܽ��г�ջ����\n");
        exit(0);
    }

    x = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    return x;
}

//��ȡջ��Ԫ��
ElemType Get(LinkedStack *S)
{
    if(S->top ==NULL)
    {
        printf("ջ�գ��޷�����ȡԪ�ز���");
        exit(0);
    }
    return S->top->data;
}

//����
void testLinkedList()
{
    LinkedStack *S;
    Init(&S);
    ElemType x;
    Push(S, 12);
    Push(S,13);
    Push(S,123);
    Pop(S);
    x = Pop(S);
    printf("%d\n",x);
    x = Pop(S);
    printf("%d\n",x);
    x = Pop(S);
    printf("%d\n",x);

}
