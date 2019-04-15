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
// ��ʼ����
void InitBTree(BinTree *BT);
//����һ��������
void CreateBTree(BinTree *BT);
//ǰ�����
void PreOrderTraverse(BinTree BT);
//�������
void InOrderTraverse(BinTree BT);
//��������
void PostOrderTraverse(BinTree BT);
void CreateNode(BinTree *node, DataType data);


void testBTree();

void visualBTree();
#endif //DATASTRUCT_BINTREE_H
