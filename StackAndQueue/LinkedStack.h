//
// Created by ys on 2019/4/11.
//

#ifndef DATASTRUCT_LINKEDSTACK_H
#define DATASTRUCT_LINKEDSTACK_H
#define ElemType int
//类型声明
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

//初始化
void Init(LinkedStack **S);
//判空操作
int Empty(LinkedStack *S);
//入栈操作
void Push(LinkedStack *S, ElemType x);
//出栈操作
ElemType Pop(LinkedStack *S);
//获取栈顶元素
ElemType Get(LinkedStack *S);

//测试
void testLinkedList();
#endif //DATASTRUCT_LINKEDSTACK_H
