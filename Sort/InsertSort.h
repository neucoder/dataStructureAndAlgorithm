//
// Created by ys on 2019/4/25.
//

#ifndef DATASTRUCT_INSERTSORT_H
#define DATASTRUCT_INSERTSORT_H
#define ElemType int


//���������ȡ�������
int getPrivot(int *SqList, int left, int right);



void bubbleSort1(ElemType *SqList, int len);
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

void readFromFile(char *fname, ElemType * arr, int arrLen);
#endif //DATASTRUCT_INSERTSORT_H
