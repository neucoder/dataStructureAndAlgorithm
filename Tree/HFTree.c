//
// Created by ys on 2019/4/15.
//

#include "HFTree.h"
#include "../tools.h"
#define DATASTRUCT_HFTREE_C
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
    return 1;
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


//����
void HFEncode(HuffmanTree *T, HFCode *H, int n)
{

    char tmpCode[n+1];
    int start = -1;
    int p = -1, c = -1; //ָʾ���ڵ��λ��,���ӽ���λ��
    tmpCode[n+1] = '\0';
    for (int i = 0; i < n; ++i) {
        start = n;
        c = i;
        while ((p = T[c].parent) > 0)
        {
            if(T[p].lchild == c)
            {
                tmpCode[--start] = '0';
            } else
            {
                tmpCode[--start] = '1';
            }
            c = p;
        }
        strcpy(H[i].bits, &tmpCode[start]);


    }
}
//����
void HFDecode(HuffmanTree *T, HFCode *H, int n)
{
    int j = -1;
    int child = 2*n-2;
    for (int i = 0; i < n; ++i) {
        j = 0;
        child = 2*n-2;
        while (H[i].bits[j] != '\0')
        {
            if(H[i].bits[j]=='0')
            {
                child = T[child].lchild;
            } else
            {
                child = T[child].rchild;
            }

            j++;
        }

        printf("����Ϊ:%s ��Ӧ�ַ�ΪnodeΪ: %d\n",H[i].bits, child);
    }
}
//����
void testHFCode()
{
    int weight[6] = {2, 3, 4, 5, 6, 7};
    char ch[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    HFCode HF[6];
    for (int i = 0; i < 6; ++i) {
        HF[i].weight = weight[i];
        HF[i].ch = ch[i];
    }


    for (int i = 0; i < 6; ++i) {
        printf("%c %d\n",HF[i].ch, HF[i].weight);
    }
    int n = 6, root = 2*n-2;
    HFTreeNode HFTree[n*2 - 1];
    CreateHuffmanTree(HFTree, weight ,n);
    HFtreeTravel(HFTree, root);

    HFEncode(HFTree, HF, n);
    for (int i = 0; i < 6; ++i) {
        printf("\n%c %d %s\n",HF[i].ch, HF[i].weight, HF[i].bits);
    }

    HFDecode(HFTree, HF, 6);
}





#endif //DATASTRUCT_HFTREE_H

