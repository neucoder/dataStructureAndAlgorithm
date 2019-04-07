//
// Created by ys on 2019/4/5.
//

#ifndef DATASTRUCT_SEQLIST_H
#define DATASTRUCT_SEQLIST_H


#define ElemType int
#define MAXSIZE 50
//�������Ա�
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
//��������
void SeqListTravel(SeqList L);
//�пղ���
int SeqListEmpty(SeqList L);
//ɾ�� ����
void SeqListDel(SeqList *L, int i);
//������
void SeqListSort(SeqList *L);

//���Ա�ϲ�����
void ListUnion(SeqList *La, SeqList *Lb);
//���Ա�ı���ϲ�
void ListMerge(SeqList *La, SeqList *Lb, SeqList*Lc);

void testSeqList();

#endif //DATASTRUCT_SEQLIST_H
