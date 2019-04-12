//
// Created by ys on 2019/4/12.
//

#ifndef DATASTRUCT_SEQQUEUE_H
#define DATASTRUCT_SEQQUEUE_H

#define ElemType int
#define MAXSIZE 5
//������е���������  ѭ������
struct Node
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};

typedef struct Node SeqQueue;

//��ʼ������
void Init(SeqQueue *Q);

//��Ӳ���
void EnQueue(SeqQueue *Q, ElemType e);

//���Ӳ���
ElemType DeQueue(SeqQueue *Q);

//����
void testQueue();

#endif //DATASTRUCT_SEQQUEUE_H
