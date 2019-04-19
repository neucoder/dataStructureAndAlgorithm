//
// Created by ys on 2019/4/15.
//

#include "HFTree.h"
#include "../tools.h"
#ifndef DATASTRUCT_HFTREE_C
#define DATASTRUCT_HFTREE_C

//构建一个哈弗曼树
int CreateHuffmanTree(HuffmanTree *T, int *weight, int n)
{
   if(n < 1)
   {
       return -1;
   }
   //树的总结点数
   int total = 2 * n-1;
   //初始化树
   for (int i = 0; i < total; ++i) {
        T[i].parent = -1;
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].weight = -1;
   }

   //对所有的叶子节点赋值
    for (int j = 0; j < n; ++j) {
        T[j].weight = weight[j];
    }
    //设置选出最小的两个树的下标
    int n1 = -1, n2 = -1;
   //选出权值较小的两个节点组成一棵树
    for (int k = n; k < total; ++k) {
        Select(T, k, &n1, &n2);
        T[n1].parent = T[n2].parent = k;
        T[k].lchild = n1;
        T[k].rchild = n2;
        T[k].weight = T[n1].weight + T[n2].weight;
    }
}
//从森林中选出两颗最小权值的树
void Select(HuffmanTree *HT, int total, int *n1, int *n2)
{
    //找出一个无父节点得树
    for (int i = 0; i < total; ++i) {
        if(HT[i].parent==-1)
        {
            *n1 = i;
            break;
        }
    }
    //找出最小权值的树
    for (int j = 0; j < total; ++j) {
        if((HT[j].weight < HT[*n1].weight) && (HT[j].parent == -1))
        {
            *n1 = j;
        }
    }

    for (int k = 0; k < total; ++k) {
        if((HT[k].parent == -1) && (k!=*n1))
        {
            *n2 = k;
            break;
        }
    }

    //选出和*n1不同的权值最小的树
    for (int l = 0; l < total; ++l) {
        if((HT[l].weight < HT[*n2].weight) && (HT[l].parent == -1) && (l != *n1))
        {
            *n2 = l;
        }
    }

}

//先序遍历哈夫曼树
void HFtreeTravel(HuffmanTree *HT, int root)
{
    if(root!=-1)
    {
        printf("%d\t", HT[root].weight);
        HFtreeTravel(HT, HT[root].lchild);
        HFtreeTravel(HT, HT[root].rchild);
    }

}

void testHTree()
{
    HuffmanTree HT[4*2-1];
    int weight[4] = {10, 5, 9, 3};
    CreateHuffmanTree(HT, weight, 4);
    HFtreeTravel(HT, 6);

}
#endif //DATASTRUCT_HFTREE_H

