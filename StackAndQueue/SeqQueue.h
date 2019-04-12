//
// Created by ys on 2019/4/12.
//

#ifndef DATASTRUCT_SEQQUEUE_H
#define DATASTRUCT_SEQQUEUE_H

#define ElemType int
#define MAXSIZE 5
//定义队列的数据类型  循环队列
struct Node
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};

typedef struct Node SeqQueue;

//初始化队列
void Init(SeqQueue *Q);

//入队操作
void EnQueue(SeqQueue *Q, ElemType e);

//出队操作
ElemType DeQueue(SeqQueue *Q);

//测试
void testQueue();

#endif //DATASTRUCT_SEQQUEUE_H
