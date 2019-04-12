//
// Created by ys on 2019/4/11.
//

#include "LinkedStack.h"
#include "../tools.h"

//初始化
void Init(LinkedStack **S)
{
    (*S) = (LinkedStack *)malloc(sizeof(LinkedStack));
    (*S)->top = NULL;
}
//判空操作
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
//入栈操作
void Push(LinkedStack *S, ElemType x)
{
    LStackNode *ls;
    ls = (LStackNode *)malloc(sizeof(LStackNode));
    if(ls == NULL)
    {
        printf("申请空间失败\n");
        exit(0);
    }
    ls->data = x;
    ls->next = S->top;
    S->top = ls;
}
//出栈操作
ElemType Pop(LinkedStack *S)
{
    LStackNode *p;
    ElemType x;
    if(S->top ==NULL)
    {
        printf("栈空不能进行出栈操作\n");
        exit(0);
    }

    x = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    return x;
}

//获取栈顶元素
ElemType Get(LinkedStack *S)
{
    if(S->top ==NULL)
    {
        printf("栈空，无法进行取元素操作");
        exit(0);
    }
    return S->top->data;
}

//测试
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
