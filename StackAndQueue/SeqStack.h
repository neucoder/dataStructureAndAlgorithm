//
// Created by ys on 2019/4/11.
//

#ifndef DATASTRUCT_SEQSTACK_H
#define DATASTRUCT_SEQSTACK_H
#define ElemType  int
#define MAXSIZE   50
#define true      1
#define false     0

//定义顺序栈类型声明
struct Node
{
    ElemType data[MAXSIZE];
    int top;
};

typedef struct Node SeqStack;

//顺序栈的初始化
void SeqStackInit(SeqStack *S);

//顺序栈的判空操作
int SeqStackEmpty(SeqStack S);

//入栈操作
void SeqStackPush(SeqStack *S, ElemType x);

//出栈操作
ElemType SeqStackPop(SeqStack *S);

//取栈顶的元素
ElemType SeqStackGet(SeqStack S);
//测试顺序栈的操作
void testSeqStack();



#endif //DATASTRUCT_SEQSTACK_H
