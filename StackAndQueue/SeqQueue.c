//
// Created by ys on 2019/4/12.
//

#include "SeqQueue.h"
#include "../tools.h"


//初始化队列
void Init(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}
//入队操作
void EnQueue(SeqQueue *Q, ElemType e)
{
    if((Q->rear+1)%MAXSIZE == Q->front)
    {
        printf("队列已满，无法进行入队操作\n");
        exit(0);
    } else
    {
        Q->rear = (Q->rear+1)%MAXSIZE;
        Q->data[Q->rear] = e;
    }
}
//出队操作
ElemType DeQueue(SeqQueue *Q)
{
    if(Q->rear == Q->front)
    {
        printf("队列已空，无法进行出队操作\n");
        exit(0);
    } else
    {
        Q->front = (Q->front+1)%MAXSIZE;
        return (Q->data[Q->front]);
    }
}


//测试
void testQueue()
{
    SeqQueue Q;
    Init(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);

    ElemType x = DeQueue(&Q);
    x = DeQueue(&Q);
    x = DeQueue(&Q);
    x = DeQueue(&Q);
    x = DeQueue(&Q);



}
