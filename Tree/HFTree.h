//
// Created by ys on 2019/4/15.
//
#define DATASTRUCT_HFTREE_H
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
//构建一个哈弗曼树
int CreateHuffmanTree(HuffmanTree *T, int *weight, int n);
//从森林中选出两颗最小权值的树
void Select(HuffmanTree *HT, int total, int *n1, int *n2);

void HFtreeTravel(HuffmanTree *HT, int root);

//哈夫曼编码解码
#define N 20
struct CodeNode
{
    char ch;
    char bits[20];
    int weight;
};

typedef struct CodeNode HFCode;

//编码
void HFEncode(HuffmanTree *T, HFCode *H, int n);
//解码
void HFDecode(HuffmanTree *T, HFCode *H, int n);
//测试
void testHFCode();

//测试
void testHTree();
#endif //DATASTRUCT_HFTREE_H
