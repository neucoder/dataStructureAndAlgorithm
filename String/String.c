//
// Created by ys on 2019/4/12.
//

#include "String.h"
#include "../tools.h"

//¥Æµƒ∏≥÷µ≤Ÿ◊˜
void SeqStringAssign(String *S, String *T)
{
    if(S->length>0)
    {
        free(S->str);
    }
    S->length = T->length;
    if(S->length >= 0)
    {
        S->str = (char *)malloc(sizeof(char));
        if(S->str==NULL)
        {
            printf("…Í«Îø’º‰ ß∞‹£°%s: %s:%d \n", __FILE__, __FUNCTION__, __LINE__);
            exit(0);
        } else
        {
            S->str = (char *)malloc((S->length+1)* sizeof(char));
            if(S->str==NULL)
            {
                printf("…Í«Îø’º‰ ß∞‹£°%s : %s :%d \n", __FILE__,__FUNCTION__, __LINE__);
                exit(0);
            }
            for (int i = 0; i < S->length; ++i) {
                S->str[i]=T->str[i];
            }
            S->str[S->length] = '\0';
        }
    }
}
//¥Æµƒ¡¨Ω”
void SeqStringContact(String *S, String *T)
{
    String tmp;
    tmp.str = NULL;
    SeqStringAssign(&tmp, S);
    S->length = S->length + T->length;
    free(S->str);
    S->str = (char *)malloc((S->length+1)* sizeof(char));
    if(S->str==NULL)
    {
        printf("…Í«Îø’º‰ ß∞‹%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);
        exit(0);
    } else
    {
        for (int i = 0; i < tmp.length; ++i) {
            S->str[i] = tmp.str[i];
        }
        for (int j = 0; j < T->length; ++j) {
            S->str[tmp.length+j] = T->str[j];
        }
        S->str[S->length] = '\0';
        free(tmp.str);
    }
}
//≈–∂œ◊÷∑˚¥Æ «∑Òœ‡µ»
int SeqStringEqual(String *S, String *T)
{
    if(S->length!=T->length)
    {
        return false;
    }
    for (int i = 0; i < S->length; ++i) {
        if(S->str[i]!=T->str[i])
        {
            return false;
        }
    }
    return true;
}
//«Û◊”◊÷∑˚¥Æµƒ≤Ÿ◊˜
void SubSeqString(String *S, String *Sub, int strat, int len)
{
    if(Sub->length!=0)
    {
        free(Sub->str);
    }
    if((0<=strat && strat <= S->length-1)&&(0<=len&&len<=S->length))
    {
        Sub->str = (char *)malloc((len+1)* sizeof(char));
        if(Sub->str==NULL)
        {
            printf("ø’º‰…Í«Î ß∞‹\n");
            exit(0);
        } else
        {
            Sub->length = len;
            for (int i = 0; i < len; ++i) {
                Sub->str[i]=S->str[strat+i];
            }
            Sub->str[len]='\0';
        }
    }
}

void testString()
{
    String S1, S2, sub, tmp;
    SeqStringInit(&S1,"hello,world");
    SeqStringInit(&sub,"");
    SubSeqString(&S1, &sub, -1, -1);
    printf("S1:%s  sub:%s\n",S1.str, sub.str);

    SubSeqString(&S1, &sub, 1, 9);
    printf("S1:%s  sub:%s\n",S1.str, sub.str);


}

//≥ı ºªØ¥Æ
void SeqStringInit(String *S, char *s)
{
    int n = strlen(s);
    (S)->length = n;
    (S)->str = (char *)malloc(((S)->length+1)* sizeof(char));
    for (int i = 0; i < n; ++i) {
        (S)->str[i] = s[i];
    }
    (S)->str[(S)->length] = '\0';

}

//KMP∆•≈‰À„∑®
int KMP(String * t, String* p, int *next)
{
    int i = 0;
    int j = 0;

    while (i < t->length && j < p->length)
    {
        if (j == -1 || t->str[i] == p->str[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }

    if (j == p->length)
        return i - j;
    else
        return -1;
}


void getNext(char * p, int * next)
{
    next[0] = -1;
    int i = 0, j = -1;

    while (i < strlen(p))
    {
        if (j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}


int SimpleMatching(String *S, String *P)
{
    int i = 0;
    while (i <= (S->length - P->length))
    {
        int j = 0;
        while (S->str[i] == P->str[j])
        {
            i++;
            j++;
        }
        if(j == P->length)
        {
            return i - P->length;
        }
        i = i - j + 1;
    }
    return -1;
}

void testSimpleMatching()
{
    String S, P;
    FILE *fp;
    fp = fopen("../data/article.txt","r");
    char c;
    int i = 0;
    int pos = -1;
    char s[1000000];


    //"Superintelligencehello"

    SeqStringInit(&P, "Superintelligencehello");
    int next[P.length];
    getNext(P.str, next);
    for (int k = 0; k < P.length; ++k) {
        printf("%d\t",next[k]);
    }
    printf("\n");
    int start = clock();
    for (int j = 0; j < 108; ++j) {
        while (((c=fgetc(fp))!=EOF) && i < 1000000)
        {
            //printf("%c",c);
            s[i++]=c;
//            i++;
        }
        S.str = s;
        S.length = i;
        int x = KMP(&S, &P, next);
                //int x = SimpleMatching(&S, &P);
        if(x == -1)
        {
            i = 0;
        } else
        {
            pos = j * 1000000 + x;
            break;
        }
    }

    int end = clock();


    fclose(fp);


    printf("%d\n  ∫ƒ ±£∫%d ms", pos, end-start);

}


void testKMP()
{
    String S,P;

    SeqStringInit(&S, "abcabcabcd");
    SeqStringInit(&P, "abcd");
    int next[P.length];
    getNext(P.str, next);
    int x = KMP(&S, &P, next);
    printf("%d",x);
}




