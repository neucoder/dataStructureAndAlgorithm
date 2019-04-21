//
// Created by ys on 2019/4/15.
//
#define DATASTRUCT_HFTREE_H
#ifndef DATASTRUCT_HFTREE_H
#define DATASTRUCT_HFTREE_H

#define MAXSIZE 1000

//���������Ķ���
struct node
{
    int weight;
    int parent;
    int lchild;
    int rchild;
};

typedef struct node HFTreeNode;
typedef HFTreeNode HuffmanTree;
//����һ����������
int CreateHuffmanTree(HuffmanTree *T, int *weight, int n);
//��ɭ����ѡ��������СȨֵ����
void Select(HuffmanTree *HT, int total, int *n1, int *n2);

void HFtreeTravel(HuffmanTree *HT, int root);

//�������������
#define N 20
struct CodeNode
{
    char ch;
    char bits[20];
    int weight;
};

typedef struct CodeNode HFCode;

//����
void HFEncode(HuffmanTree *T, HFCode *H, int n);
//����
void HFDecode(HuffmanTree *T, HFCode *H, int n);
//����
void testHFCode();

//����
void testHTree();
#endif //DATASTRUCT_HFTREE_H
