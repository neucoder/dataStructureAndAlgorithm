//
// Created by ys on 2019/4/23.
//

#ifndef DATASTRUCT_LINKLISTSEARCH_H
#define DATASTRUCT_LINKLISTSEARCH_H
//˳����ҷ�

#define ElemType int
//���Բ���
int SqListSearch(ElemType *SqList, int key, int len);

void testSqlistSearch();


//�۰���ҷ�

int BinSearch(ElemType *SqList, int key, int low, int high);

//�۰���ҵݹ��㷨
int RBinSearch(ElemType *SqList, int key, int low, int high);

void testBSearch();

#endif //DATASTRUCT_LINKLISTSEARCH_H
