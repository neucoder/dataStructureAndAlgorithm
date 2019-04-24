//
// Created by ys on 2019/4/21.
//

#include "AdjLinkedList.h"
#include "../tools.h"

#define DATASTRUCT_ADJLINKEDLIST_C
#ifndef DATASTRUCT_ADJLINKEDLIST_C
#define DATASTRUCT_ADJLINKEDLIST_C
void CreateALGraph(ALGraph *G)
{
    FILE *fp;
    char *fname = "../data/graph.txt";
    fp = fopen(fname,"r");
    char ch;
    int n, e;
    fscanf(fp,"%d %d\n", &n, &e);
    G->n = n;
    G->e = e;
    char vexdata = -1;
    for (int i = 0; i < G->n; ++i) {
        fscanf(fp,"%c\n", &vexdata);
        G->adjlist[i].vexdata = vexdata;
        G->adjlist[i].firstarc = NULL;
        printf("%c\n",G->adjlist[i].vexdata);
    }
    EdgeNode *E;
    char head, end;
    int weight;
    for (int j = 0; j < G->e; ++j) {
        fscanf(fp,"(%c, %c, %d)\n",&head, &end, &weight);
        E = (EdgeNode *)malloc(sizeof(EdgeNode));
        E->adjvex = end - 'a';
        E->nextarc = G->adjlist[head-'a'].firstarc;
        E->info = weight;
        G->adjlist[head - 'a'].firstarc = E;
        printf("end %d\n", E->adjvex);
    }
    EdgeNode *p;
    for (int i = 0; i < G->n; ++i) {
        p=G->adjlist[i].firstarc;
        while (p!=NULL)
        {
            printf("%c weitght:%d-> %c",G->adjlist[i].vexdata, p->info, G->adjlist[p->adjvex].vexdata);
            p=p->nextarc;
            printf("\n");
        }
        printf("\n");
    }
}


void test()
{
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph));
    if(G == NULL)
    {
        printf("创建图的时候,申请空间失败\n");
        exit(-1);
    }

    CreateALGraph(G);

    free(G);
}
#endif