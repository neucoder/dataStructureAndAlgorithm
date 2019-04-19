//
// Created by ys on 2019/4/15.
//

#include "HFTree.h"
#include "../tools.h"
#ifndef DATASTRUCT_HFTREE_C
#define DATASTRUCT_HFTREE_C

//����һ����������
int CreateHuffmanTree(HuffmanTree *T, int *weight, int n)
{
   if(n < 1)
   {
       return -1;
   }
   //�����ܽ����
   int total = 2 * n-1;
   //��ʼ����
   for (int i = 0; i < total; ++i) {
        T[i].parent = -1;
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].weight = -1;
   }

   //�����е�Ҷ�ӽڵ㸳ֵ
    for (int j = 0; j < n; ++j) {
        T[j].weight = weight[j];
    }
    //����ѡ����С�����������±�
    int n1 = -1, n2 = -1;
   //ѡ��Ȩֵ��С�������ڵ����һ����
    for (int k = n; k < total; ++k) {
        Select(T, k, &n1, &n2);
        T[n1].parent = T[n2].parent = k;
        T[k].lchild = n1;
        T[k].rchild = n2;
        T[k].weight = T[n1].weight + T[n2].weight;
    }
}
//��ɭ����ѡ��������СȨֵ����
void Select(HuffmanTree *HT, int total, int *n1, int *n2)
{
    //�ҳ�һ���޸��ڵ����
    for (int i = 0; i < total; ++i) {
        if(HT[i].parent==-1)
        {
            *n1 = i;
            break;
        }
    }
    //�ҳ���СȨֵ����
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

    //ѡ����*n1��ͬ��Ȩֵ��С����
    for (int l = 0; l < total; ++l) {
        if((HT[l].weight < HT[*n2].weight) && (HT[l].parent == -1) && (l != *n1))
        {
            *n2 = l;
        }
    }

}

//���������������
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

