//
// Created by ys on 2019/4/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"


//˳��ջ�ĳ�ʼ��
void SeqStackInit(SeqStack *S)
{
    S->top = -1;
}

//˳��ջ���пղ���
int SeqStackEmpty(SeqStack S)
{
    if(S.top == -1)
    {
        return true;
    } else
    {
        return false;
    }
}

//��ջ����
void SeqStackPush(SeqStack *S, ElemType x)
{
    if(S->top == MAXSIZE - 1)
    {
        printf("ջ����\n");
        exit(0);
    }
    S->top++;
    S->data[S->top] = x;
}

//��ջ����
ElemType SeqStackPop(SeqStack *S)
{
    if(SeqStackEmpty(*S))
    {
        printf("ջ�ѿգ��޷����г�ջ����\n");
        exit(0);
    } else
    {
        ElemType x = S->data[S->top];
        S->top--;
        return x;
    }
}


//ȡջ����Ԫ��
ElemType SeqStackGet(SeqStack S)
{
    if(SeqStackEmpty(S))
    {
        printf("ջ�ѿգ��޷���ȡջ��Ԫ��\n");
        return 0;
    }
    return S.data[S.top];
}

//����˳��ջ�Ĳ���
void testSeqStack()
{
    SeqStack S;
    SeqStackInit(&S);
    int b = SeqStackEmpty(S);
    SeqStackPush(&S, 1);
    b = SeqStackEmpty(S);

    ElemType x = SeqStackPop(&S);
    for (int i = 0; i < 49; ++i) {
        SeqStackPush(&S, i);
    }

    x = SeqStackGet(S);
    x = SeqStackPop(&S);
    x = SeqStackPop(&S);
    x = SeqStackPop(&S);
    x = SeqStackPop(&S);
    x = SeqStackPop(&S);
    x = SeqStackPop(&S);

}
