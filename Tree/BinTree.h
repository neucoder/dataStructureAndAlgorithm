//
// Created by ys on 2019/4/14.
//
#define DATASTRUCT_BINTREE_H
#ifndef DATASTRUCT_BINTREE_H
#define DATASTRUCT_BINTREE_H
#define DataType char

typedef struct node
{
    DataType data;
    struct node *lchild, *rchild;
} BinNode;
typedef BinNode *BinTree;
// 初始化树
void InitBTree(BinTree *BT);
//创建一个二叉树
void CreateBTree(BinTree *BT);
//前序遍历
void PreOrderTraverse(BinTree BT);
//中序遍历
void InOrderTraverse(BinTree BT);
//后续遍历
void PostOrderTraverse(BinTree BT);
void CreateNode(BinTree *node, DataType data);


void testBTree();

void visualBTree();
#endif //DATASTRUCT_BINTREE_H
