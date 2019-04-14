//
// Created by ys on 2019/4/14.
//
#include "../tools.h"
#include "BinTree.h"
void InitBTree(BinTree *BT)
{
    (*BT) = NULL;
}
//创建一个二叉树
void CreateBTree(BinTree *BT)
{
    CreateNode(BT, 'A');
    BinTree B,C,D,E,F,G,H,N,O;
    CreateNode(&B, 'B');
    CreateNode(&C, 'C');
    CreateNode(&D, 'D');
    CreateNode(&E, 'E');
    CreateNode(&F, 'F');
    CreateNode(&G, 'G');
    CreateNode(&H, 'H');
    CreateNode(&N, 'N');
    CreateNode(&O, 'O');
    (*BT)->lchild = B;
    (*BT)->rchild = C;
    B->lchild = D;
    B->rchild = E;
    D->lchild = H;
    C->rchild = G;
    G->lchild = N;
    G->rchild = O;

}

void CreateNode(BinTree *node, DataType data)
{
    (*node) = (BinNode *)malloc(sizeof(BinNode));
    (*node)->data = data;
    (*node)->lchild = NULL;
    (*node)->rchild = NULL;
}
//前序遍历
void PreOrderTraverse(BinTree BT)
{
    if(BT)
    {
        printf("%c\t",BT->data);
        PreOrderTraverse(BT->lchild);
        PreOrderTraverse(BT->rchild);

    }

}
//中序遍历
void InOrderTraverse(BinTree BT)
{
    if(BT)
    {

        InOrderTraverse(BT->lchild);
        printf("%c\t",BT->data);
        InOrderTraverse(BT->rchild);
    }
}
//后续遍历
void PostOrderTraverse(BinTree BT)
{
    if(BT)
    {
        PreOrderTraverse(BT->lchild);
        PreOrderTraverse(BT->rchild);
        printf("%c\t",BT->data);
    }
}

void visualBTree();


void testBTree()
{
    BinTree BT;
    CreateBTree(&BT);
    //printf("\n");
    PreOrderTraverse(BT);
    //printf("\n");
    //InOrderTraverse(BT);
    //printf("\n");
    //PostOrderTraverse(BT);

}