//
// Created by ys on 2019/4/11.
//

#ifndef DATASTRUCT_SEQSTACK_H
#define DATASTRUCT_SEQSTACK_H
#define ElemType  int
#define MAXSIZE   50
#define true      1
#define false     0

//����˳��ջ��������
struct Node
{
    ElemType data[MAXSIZE];
    int top;
};

typedef struct Node SeqStack;

//˳��ջ�ĳ�ʼ��
void SeqStackInit(SeqStack *S);

//˳��ջ���пղ���
int SeqStackEmpty(SeqStack S);

//��ջ����
void SeqStackPush(SeqStack *S, ElemType x);

//��ջ����
ElemType SeqStackPop(SeqStack *S);

//ȡջ����Ԫ��
ElemType SeqStackGet(SeqStack S);
//����˳��ջ�Ĳ���
void testSeqStack();



#endif //DATASTRUCT_SEQSTACK_H
