//
// Created by ys on 2019/4/25.
//

#ifndef DATASTRUCT_INSERTSORT_H
#define DATASTRUCT_INSERTSORT_H
#define ElemType int
//ֱ�Ӳ������򣬲������
void straipass(ElemType *SqList, ElemType key, int len);
//ֱ�Ӳ�������
void straiSort(ElemType *SqList, int len);

//�۰��������
void binInsertSort(ElemType *SqList, int len);

//��·��������
void twoSort(ElemType *SqList, int len);

//ϣ������

void shellSort(ElemType *SqList, int len);

void bstraipass(ElemType *SqList, ElemType key, int len);

void testSort();
#endif //DATASTRUCT_INSERTSORT_H
