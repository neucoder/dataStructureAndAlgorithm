//
// Created by ys on 2019/4/14.
//

//条件编译注释掉
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
//删除二叉树
void DestroyBTree(BinTree *BT);
//清空二叉树
void ClearBTRee(BinTree *BT);
//二叉树判空

int BTreeEmpty(BinTree BT);
//求二叉树的深度
int BTreeDepth(BinTree BT);
//返回二叉树的树根
BinTree Root(BinTree BT);
//求二叉树的双亲结点,若x是非根结点返回双亲，否则返回空
BinTree Parent(BinTree BT, BinTree x);

//求左孩子
BinTree LeftChild(BinTree BT,BinTree x);

//求右孩子
BinTree RightChild(BinTree BT,BinTree x);


//求左兄弟
BinTree LeftSibling(BinTree BT, BinTree x);

//求右兄弟
BinTree RightSibling(BinTree BT, BinTree x);


//插入左孩子
void InsertLeftChild(BinTree BT, BinTree p, BinTree x);


//插入右孩子
BinTree InsertRightChild(BinTree BT, BinTree p, BinTree x);


//删除左孩子

void DeleteLeftChild(BinTree BT, BinTree p);
//删除右孩子
void DeleteRightChild(BinTree BT, BinTree p);


//二叉树遍历

//前序遍历
void PreOrderTraverse(BinTree BT);
//中序遍历
void InOrderTraverse(BinTree BT);
//后续遍历
void PostOrderTraverse(BinTree BT);
void CreateNode(BinTree *node, DataType data);

void testRoot();

void visualBTree();
#endif //DATASTRUCT_BINTREE_H
