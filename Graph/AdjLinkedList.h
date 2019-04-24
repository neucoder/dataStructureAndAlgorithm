//
// Created by ys on 2019/4/21.
//
#define DATASTRUCT_ADJLINKEDLIST_H
#ifndef DATASTRUCT_ADJLINKEDLIST_H
#define DATASTRUCT_ADJLINKEDLIST_H

#define MaxVertexNum 100
#define VertexType char
#define EdgeType int

//邻接表法

//邻接表的表结点，包含边的信息
typedef struct node
{
    int adjvex;//顶点位置
    struct node *nextarc;
    int info;//边的数据信息
} EdgeNode;


//表头结点，顶点结点
typedef struct vnode
{
    VertexType vexdata;
    EdgeNode *firstarc;
}VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct
{
    AdjList adjlist;
    int n, e;
}ALGraph;
//创建图的数据结构
void CreateALGraph(ALGraph *G);

void test();

#endif //DATASTRUCT_ADJLINKEDLIST_H
