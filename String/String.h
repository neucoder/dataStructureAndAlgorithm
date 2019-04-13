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


//初始化串
void SeqStringInit(String *S, char *s);
//串的赋值操作
void SeqStringAssign(String *S, String *T);
//串的连接
void SeqStringContact(String *S, String *T);
//判断字符串是否相等
int SeqStringEqual(String *S, String *T);
//求子字符串的操作
void SubSeqString(String *S, String *Sub, int strat, int len);
int KMP(String *S, String *P);
//简单匹配算法
int SimpleMatching(String *S, String *P);

void testSimpleMatching();
void testString();

#endif //DATASTRUCT_STRING_H
