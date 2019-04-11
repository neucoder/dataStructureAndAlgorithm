//
// Created by ys on 2019/4/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"


//顺序栈的初始化
void SeqStackInit(SeqStack *S)
{
    S->top = -1;
}

//顺序栈的判空操作
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

//入栈操作
void SeqStackPush(SeqStack *S, ElemType x)
{
    if(S->top == MAXSIZE - 1)
    {
        printf("栈已满\n");
        exit(0);
    }
    S->top++;
    S->data[S->top] = x;
}

//出栈操作
ElemType SeqStackPop(SeqStack *S)
{
    if(SeqStackEmpty(*S))
    {
        printf("栈已空，无法进行出栈操作\n");
        exit(0);
    } else
    {
        ElemType x = S->data[S->top];
        S->top--;
        return x;
    }
}


//取栈顶的元素
ElemType SeqStackGet(SeqStack S)
{
    if(SeqStackEmpty(S))
    {
        printf("栈已空，无法获取栈顶元素\n");
        return 0;
    }
    return S.data[S.top];
}

//测试顺序栈的操作
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
