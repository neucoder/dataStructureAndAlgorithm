//
// Created by ys on 2019/4/12.
//

#ifndef DATASTRUCT_LINKEDQUEUE_H
#define DATASTRUCT_LINKEDQUEUE_H
#define ElemType int
struct Node
{
    ElemType data;
    struct Node *next;
};

typedef struct Node QNOde;
typedef struct Node *LinkedQNode;

struct HQueue
{
    QNOde *front;
    QNOde *rear;
};

typedef struct HQueue Queue;
typedef struct HQueue *LQueue;

//初始化
void Init(LQueue *Q);
//队判空操作
int Empty(LQueue Q);
//入队操作
void EnQueue(LQueue Q, ElemType e);
//出队操作
ElemType Dequeue(LQueue *Q);

//测试
void testQueue();



#endif //DATASTRUCT_LINKEDQUEUE_H
