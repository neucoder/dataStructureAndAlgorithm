//
// Created by ys on 2019/4/23.
//

#ifndef DATASTRUCT_LINKLISTSEARCH_H
#define DATASTRUCT_LINKLISTSEARCH_H
//顺序查找法

#define ElemType int
//线性查找
int SqListSearch(ElemType *SqList, int key, int len);

void testSqlistSearch();


//折半查找法

int BinSearch(ElemType *SqList, int key, int low, int high);

//折半查找递归算法
int RBinSearch(ElemType *SqList, int key, int low, int high);

void testBSearch();

#endif //DATASTRUCT_LINKLISTSEARCH_H
