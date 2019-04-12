//
// Created by ys on 2019/4/12.
//

#include "String.h"
#include "../tools.h"

//串的赋值操作
void SeqStringAssign(String *S, String *T)
{
    if(S->str)
    {
        free(S->str);
    }
    S->length = T->length;
    if(S->length == 0)
    {
        S->str = (char *)malloc(sizeof(char));
        if(S->str==NULL)
        {
            printf("申请空间失败！%s :%d ", __FILE__, __LINE__);
            exit(0);
        } else
        {
            S->str = (char *)malloc((S->length+1)* sizeof(char));
            if(S->str==NULL)
            {
                printf("申请空间失败！%s :%d ", __FILE__, __LINE__);
                exit(0);
            }
            for (int i = 0; i < S->length; ++i) {
                S->str[i]=T->str[i];
            }
            S->str[S->length+1] = '\0';
        }
    }
}
//串的连接
void SeqStringContact(String *S, String *T);
//判断字符串是否相等
void SeqStringEqual(String *S, String *T);
//求子字符串的操作
void SubSeqString(String *S, String *Sub, int strat, int len);