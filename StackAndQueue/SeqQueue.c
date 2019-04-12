//
// Created by ys on 2019/4/12.
//

#include "SeqQueue.h"
#include "../tools.h"


//��ʼ������
void Init(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}
//��Ӳ���
void EnQueue(SeqQueue *Q, ElemType e)
{
    if((Q->rear+1)%MAXSIZE == Q->front)
    {
        printf("�����������޷�������Ӳ���\n");
        exit(0);
    } else
    {
        Q->rear = (Q->rear+1)%MAXSIZE;
        Q->data[Q->rear] = e;
    }
}
//���Ӳ���
ElemType DeQueue(SeqQueue *Q)
{
    if(Q->rear == Q->front)
    {
        printf("�����ѿգ��޷����г��Ӳ���\n");
        exit(0);
    } else
    {
        Q->front = (Q->front+1)%MAXSIZE;
        return (Q->data[Q->front]);
    }
}


//����
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
