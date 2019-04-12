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

//��ʼ��
void Init(LQueue *Q);
//���пղ���
int Empty(LQueue Q);
//��Ӳ���
void EnQueue(LQueue Q, ElemType e);
//���Ӳ���
ElemType Dequeue(LQueue *Q);

//����
void testQueue();



#endif //DATASTRUCT_LINKEDQUEUE_H
