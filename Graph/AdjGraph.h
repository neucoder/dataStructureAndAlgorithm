//
// Created by ys on 2019/4/15.
//

#ifndef DATASTRUCT_ADJGRAPH_H
#define DATASTRUCT_ADJGRAPH_H

#define MaxVertexNum 100
#define VertexType char
#define EdgeType int

typedef struct {
    VertexType vexs[MaxVertexNum];
    EdgeType edges[MaxVertexNum][MaxVertexNum];
    int n, e;
}AdjGraph;






#endif //DATASTRUCT_ADJGRAPH_H
