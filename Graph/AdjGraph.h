//
// Created by ys on 2019/4/15.
//

#define DATASTRUCT_ADJGRAPH_H
#ifndef DATASTRUCT_ADJGRAPH_H
#define DATASTRUCT_ADJGRAPH_H


//邻接矩阵法
#define MaxVertexNum 100
#define VertexType char
#define EdgeType int

typedef struct {
    VertexType vexs[MaxVertexNum]; //顶点表
    EdgeType edges[MaxVertexNum][MaxVertexNum];//邻接矩阵
    int n, e;
}AdjGraph;
//构造图
void createGraph(AdjGraph *G);

void test();


#endif //DATASTRUCT_ADJGRAPH_H
