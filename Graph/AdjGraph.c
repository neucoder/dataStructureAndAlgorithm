//
// Created by ys on 2019/4/15.
//

#include "../tools.h"
#include "AdjGraph.h"
#define DATASTRUCT_ADJGRAPH_C
#ifndef DATASTRUCT_ADJGRAPH_C
#define DATASTRUCT_ADJGRAPH_C

//构造图
void createGraph(AdjGraph *G)
{
    FILE *fp;
    char *fname = "../data/graph.txt";
    fp = fopen(fname, "r");
    if(fp==NULL)
    {
        printf("文件操作打开不成功\n");
        exit(-1);
    }
    char ch;
    int i = 0;
    fscanf(fp, "%d %d\n",&(G->n), &(G->e));
    while ((ch = fgetc(fp))!='#')
    {
        if(ch == '\n')
        {
            continue;
        }
        G->vexs[i] = ch;
        i ++;
    }
    fgetc(fp);
    int weight = -1;
    char c1 = 'X', c2 = 'X';
//    while ((ch = fgetc(fp))!=EOF)
//    {
//        putchar(ch);
//    }
    for (int j = 0; j < G->n; ++j) {
        for (int k = 0; k < G->n; ++k) {
            G->edges[j][k] = -1;
        }
    }
    while (fscanf(fp, "(%c, %c, %d)\n", &c1, &c2, &weight)!=EOF)
    {
        printf("c1:%c c2:%c weight:%d\n",c1,c2,weight);
        G->edges[c1-'a'][c2-'a'] = weight;
    }

    for (int j = 0; j < G->n; ++j) {
        for (int k = 0; k < G->n; ++k) {
            printf("%5d",G->edges[j][k]);
        }
        printf("\n");
    }
    fclose(fp);
}


void test()
{
    AdjGraph *G = (AdjGraph*)malloc(sizeof(AdjGraph));

    createGraph(G);
//    FILE *fp;
//    fp = fopen("test.txt","r");
//    char c1,c2;
//    int a;
//    while (fscanf(fp,"(%c, %c, %d)\n",&c1,&c2,&a)!=EOF)
//    {
//        printf("%c %c %d\n",c1,c2,a);
//    }
//
//    fclose(fp);
}


#endif //DATASTRUCT_ADJGRAPH_H