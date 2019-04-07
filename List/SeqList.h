//
// Created by ys on 2019/4/5.
//

#ifndef DATASTRUCT_SEQLIST_H
#define DATASTRUCT_SEQLIST_H


#define ElemType int
#define MAXSIZE 50
//定义线性表
struct node {
    ElemType data[MAXSIZE];
    int length;
};

typedef struct node SeqList;



ElemType SeqListGet(SeqList L, int i);
void SeqListInit(SeqList *L);
void SeqListInsert(SeqList *L, int i, ElemType b);
ElemType SeqListNext(SeqList L, ElemType e);
ElemType SeqListPrior(SeqList L, ElemType e);
int SeqlistLocate(SeqList L, ElemType e);

int SeqListLength(SeqList L);
//遍历操作
void SeqListTravel(SeqList L);
//判空操作
int SeqListEmpty(SeqList L);
//删除 操作
void SeqListDel(SeqList *L, int i);
//表排序
void SeqListSort(SeqList *L);

//线性表合并操作
void ListUnion(SeqList *La, SeqList *Lb);
//线性表的保序合并
void ListMerge(SeqList *La, SeqList *Lb, SeqList*Lc);

void testSeqList();

#endif //DATASTRUCT_SEQLIST_H
