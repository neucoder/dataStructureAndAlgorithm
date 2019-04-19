//
// Created by ys on 2019/4/14.
//

//��������ע�͵�
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
//ɾ��������
void DestroyBTree(BinTree *BT);
//��ն�����
void ClearBTRee(BinTree *BT);
//�������п�

int BTreeEmpty(BinTree BT);
//������������
int BTreeDepth(BinTree BT);
//���ض�����������
BinTree Root(BinTree BT);
//���������˫�׽��,��x�ǷǸ���㷵��˫�ף����򷵻ؿ�
BinTree Parent(BinTree BT, BinTree x);

//������
BinTree LeftChild(BinTree BT,BinTree x);

//���Һ���
BinTree RightChild(BinTree BT,BinTree x);


//�����ֵ�
BinTree LeftSibling(BinTree BT, BinTree x);

//�����ֵ�
BinTree RightSibling(BinTree BT, BinTree x);


//��������
void InsertLeftChild(BinTree BT, BinTree p, BinTree x);


//�����Һ���
BinTree InsertRightChild(BinTree BT, BinTree p, BinTree x);


//ɾ������

void DeleteLeftChild(BinTree BT, BinTree p);
//ɾ���Һ���
void DeleteRightChild(BinTree BT, BinTree p);


//����������

//ǰ�����
void PreOrderTraverse(BinTree BT);
//�������
void InOrderTraverse(BinTree BT);
//��������
void PostOrderTraverse(BinTree BT);
void CreateNode(BinTree *node, DataType data);

void testRoot();

void visualBTree();
#endif //DATASTRUCT_BINTREE_H
