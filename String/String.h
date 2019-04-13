//
// Created by ys on 2019/4/12.
//

#ifndef DATASTRUCT_STRING_H
#define DATASTRUCT_STRING_H

struct Node
{
    char *str;
    int length;
};
typedef struct Node String;

void test();


//��ʼ����
void SeqStringInit(String *S, char *s);
//���ĸ�ֵ����
void SeqStringAssign(String *S, String *T);
//��������
void SeqStringContact(String *S, String *T);
//�ж��ַ����Ƿ����
int SeqStringEqual(String *S, String *T);
//�����ַ����Ĳ���
void SubSeqString(String *S, String *Sub, int strat, int len);

void testString();

#endif //DATASTRUCT_STRING_H
