//
// Created by ys on 2019/4/12.
//

#include "LinkedQueue.h"
#include "../tools.h"

//��ʼ��
void Init(LQueue *Q) {
    (*Q) = (LQueue) malloc(sizeof(Queue));
    QNOde *q = (QNOde *) malloc(sizeof(QNOde));
    q->next = NULL;
    (*Q)->rear = (*Q)->front = q;
}

//���пղ���
int Empty(LQueue Q) {
    if ((Q->front) == (Q->rear)) {
        return true;
    } else {
        return false;
    }
}

//��Ӳ���
void EnQueue(LQueue Q, ElemType e) {
    QNOde *q = (QNOde *) malloc(sizeof(QNOde));
    if (q == NULL) {
        printf("����ռ�ʧ��\n");
        exit(0);
    }
    q->data = e;
    q->next = NULL;
    Q->rear->next = q;
    Q->rear = q;
}
//���Ӳ���
ElemType Dequeue(LQueue *Q) {
    if (Empty(*Q)) {
        printf("�����ѿգ��޷����г��Ӳ���\n");
        exit(0);
    }

    QNOde *q = (*Q)->front->next;
    (*Q)->front->next = q->next;
    ElemType x = q->data;
    free(q);
    if ((*Q)->front->next == NULL) {
        (*Q)->rear = (*Q)->front;
    }
    return x;
}


//����
void testQueue() {
    LQueue Q;
    Init(&Q);
    int bool = Empty(Q);
    EnQueue(Q, 1);
    bool = Empty(Q);
    for (int i = 2; i < 10; ++i) {
        EnQueue(Q, i);
    }
    ElemType x;
    for (int j = 0; j < 10; ++j) {
        x = Dequeue(&Q);
        printf("%d\n",x);
    }
}
