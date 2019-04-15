//
// Created by ys on 2019/4/15.
//

#ifndef DATASTRUCT_HFTREE_H
#define DATASTRUCT_HFTREE_H

#define MAXSIZE 1000

//哈夫曼树的定义
struct node
{
    int weight;
    int parent;
    int lchild;
    int rchild;
};

typedef struct node HFTreeNode;
typedef HFTreeNode HuffmanTree;


#endif //DATASTRUCT_HFTREE_H
