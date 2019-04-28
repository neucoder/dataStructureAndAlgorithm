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


//ѡ������
void selectSort(ElemType *SqList, int len);

void bstraipass(ElemType *SqList, ElemType key, int len);

void testSort();
void timeOfSort(char *dataFile, void (*fun)(ElemType *Sqlist, int len), char *funName, ElemType *SqList, int N);

//����Ϊ�󶥶�
//���ε���ʹ��Ϊһ�����ݹ��ɴ󶥶�
void heapAdjust(ElemType *SqList, int s, int m);

//������
void HeapSort(ElemType *SqList, int len);
void readFromFile(char *fname, ElemType * arr, int arrLen);


//��·�鲢����

void mergeSort(ElemType *SqList, int len);
void mSort(ElemType *A, ElemType *tmparr, int left, int right);
void merge(ElemType *A, ElemType *tmparr, int left, int center, int right);


#endif //DATASTRUCT_INSERTSORT_H
