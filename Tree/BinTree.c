//
// Created by ys on 2019/4/14.
//
#include "../tools.h"
#include "BinTree.h"

//#define DATASTRUCT_BINTREE_C
#ifndef DATASTRUCT_BINTREE_C
#define DATASTRUCT_BINTREE_C

void InitBTree(BinTree *BT) {
    (*BT) = NULL;
}
//����һ��������

/*
 *
 *               A
 *             /   \
 *            B     C
 *           / \     \
 *          D   E     G
 *         /         / \
 *        H         N   O
 *
 *
 * */
void CreateBTree(BinTree *BT) {
    CreateNode(BT, 'A');
    BinTree B, C, D, E, F, G, H, N, O;
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


//ɾ��������
void DestroyBTree(BinTree *BT) {
    if (*BT) {
        //�ݹ�ɾ�������
        DestroyBTree(&((*BT)->lchild));
        DestroyBTree(&((*BT)->rchild));
        if ((*BT)->lchild == NULL && (*BT)->rchild == NULL) {
            free((*BT));
            (*BT) = NULL;
        }
    }
}

//��ն�����
void ClearBTRee(BinTree *BT);
//�������п�

int BTreeEmpty(BinTree BT) {
    if (BT == NULL) {
        return 1;
    }
    return 0;
}

//������������
int BTreeDepth(BinTree BT) {
    if (BT == NULL) {
        return 0;
    }

    int left = BTreeDepth(BT->lchild);
    int right = BTreeDepth(BT->rchild);
    return (left >= right ? left + 1 : right + 1);
}

//���ض�����������
BinTree Root(BinTree BT) {
    if (BT != NULL) {
        return BT;
    } else {
        return NULL;
    }
}

//���������˫�׽��,��x�ǷǸ���㷵��˫�ף����򷵻ؿ�
BinTree Parent(BinTree BT, BinTree x) {


    if(BT) {
        if(BT->lchild == x || BT->rchild == x)
        {
            return BT;
        }
        BinTree left = Parent(BT->lchild, x);
        BinTree right = Parent(BT->rchild, x);
        return (left!=NULL) ?left:right;
    }
    return NULL;
}

//������
BinTree LeftChild(BinTree BT, BinTree x) {

    if(BT) {
        if (BT == x) {
            return BT->lchild;
        }

        BinTree left = LeftChild(BT->lchild, x);
        BinTree right = LeftChild(BT->rchild, x);
        return (left!=NULL)?left:right;
    }
    return NULL;
}

//���Һ���
BinTree RightChild(BinTree BT, BinTree x) {
    if(BT) {
        if (BT == x) {
            return BT->rchild;
        }

        BinTree left = RightChild(BT->lchild, x);
        BinTree right = RightChild(BT->rchild, x);
        return (left!=NULL)?left:right;
    }

    return NULL;
}


//�����ֵ�
BinTree LeftSibling(BinTree BT, BinTree x)
{
    BinTree parent = Parent(BT, x);
    if(parent)
    {
        if(parent->lchild == x)
            return NULL;
        return parent->lchild;
    } else{
        return NULL;
    }
}


//�����ֵ�
BinTree RightSibling(BinTree BT, BinTree x)
{
    BinTree parent = Parent(BT, x);
    if(parent)
    {
        return parent->rchild;
    } else{
        return NULL;
    }

}


//��������
BinTree InsertLeftChild(BinTree BT, BinTree p, BinTree x);


//�����Һ���
BinTree InsertRightChild(BinTree BT, BinTree p, BinTree x);


//ɾ������

void DeleteLeftChild(BinTree BT, BinTree p);

//ɾ���Һ���
void DeleteRightChild(BinTree BT, BinTree p);


void CreateNode(BinTree *node, DataType data) {
    (*node) = (BinNode *) malloc(sizeof(BinNode));
    (*node)->data = data;
    (*node)->lchild = NULL;
    (*node)->rchild = NULL;
}

//ǰ�����
void PreOrderTraverse(BinTree BT) {
    if (BT) {
        printf("%c\t", BT->data);
        PreOrderTraverse(BT->lchild);
        PreOrderTraverse(BT->rchild);

    }

}

//�������
void InOrderTraverse(BinTree BT) {
    if (BT) {

        InOrderTraverse(BT->lchild);
        printf("%c\t", BT->data);
        InOrderTraverse(BT->rchild);
    }
}

//��������
void PostOrderTraverse(BinTree BT) {
    if (BT) {
        PreOrderTraverse(BT->lchild);
        PreOrderTraverse(BT->rchild);
        printf("%c\t", BT->data);
    }
}

void visualBTree();


void testRoot() {
    BinTree BT, A, B, C, D, E, F, G, H, N, O;
    CreateBTree(&BT);
    A = BT;
    B = A->lchild;
    C = A->rchild;
    D = B->lchild;
    E = B->rchild;
    H = D->lchild;
    G = C->rchild;
    N = G->lchild;
    O = G->rchild;
    BinTree tmp;
    tmp = LeftSibling(BT, BT);
    tmp = LeftSibling(BT, B);
    tmp = LeftSibling(BT, C);
    tmp = LeftSibling(BT, D);
    tmp = LeftSibling(BT, E);
    tmp = LeftSibling(BT, H);
    tmp = LeftSibling(BT, G);
    tmp = LeftSibling(BT, N);
    tmp = LeftSibling(BT, O);



    /*
    tmp = LeftChild(BT, BT);
    tmp = LeftChild(BT, B);
    tmp = LeftChild(BT, D);
    tmp = LeftChild(BT, C);//
    tmp = LeftChild(BT, G);//


    tmp = RightChild(BT, BT);
    tmp = RightChild(BT, B);
    tmp = RightChild(BT, D);
    tmp = RightChild(BT, C);//
    tmp = RightChild(BT, G);//

     */


}



#endif