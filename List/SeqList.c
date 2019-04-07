#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"


//��ʼ��
void SeqListInit(SeqList *L) {
    L->length = 0;
}

//�󳤶�
int SeqListLength(SeqList L) {
    return L.length;
}

//ȡԪ��
ElemType SeqListGet(SeqList L, int i) {
    if ((i >= 1) && (i <= L.length)) {
        return L.data[i - 1];
    } else {
        printf("iֵ���Ϸ�\n");
        exit(0);
    }
}

//��λ����
int SeqlistLocate(SeqList L, ElemType e) {
    int i = 0;
    while ((i <= L.length) && (e != L.data[i])) {
        i++;
    }

    if (i <= L.length) {
        return i+1;
    } else {
        printf("��Ԫ�ز��ڱ���\n");
        return 0;
    }
}


//��ǰ������
ElemType SeqListPrior(SeqList L, ElemType e) {
    int i = SeqlistLocate(L, e);
    if (1 == i) {
        printf("��һ��Ԫ��û��ǰ��\n");
        exit(0);
    } else {
        return L.data[i - 2];
    }
}

//���̲���
ElemType SeqListNext(SeqList L, ElemType e) {
    int i = SeqlistLocate(L, e);
    if (L.length == i) {
        printf("���һ��Ԫ��û�к��\n");
        exit(0);
    } else {
        return L.data[i];
    }
}

//ǰ�����
void SeqListInsert(SeqList *L, int i, ElemType b) {
    if (L->length == MAXSIZE) {
        printf("���������޷����в������\n");
        exit(0);
    }
    if ((i < 1) || (i > L->length + 1)) {
        printf("iֵ���Ϸ�\n");
        exit(0);
    }
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];

    }

    L->data[i - 1] = b;
    L->length++;
}

//ɾ�� ����
void SeqListDel(SeqList *L, int i) {
    if ((i < 1) || (i > L->length)) {
        printf("iֵ���Ϸ�\n");
        exit(0);
    }
    for (int j = i; j <= L->length - 1; j++) {
        L->data[j - 1] = L->data[j];
    }

    L->length--;

}

//�пղ���
int SeqListEmpty(SeqList L) {
    return !L.length;
}

//��������
void SeqListTravel(SeqList L) {
    printf("-------------------------------------------\n");
    if (SeqListEmpty(L)) {
        printf("����һ���ձ�\n");
    } else {
        for (int i = 1; i <= L.length; ++i) {
            printf("��%d��Ԫ����%d\n", i, L.data[i - 1]);
        }
    }
}

//���Ա�ı���ϲ�
void ListMerge(SeqList *La, SeqList *Lb, SeqList *Lc) {
    SeqListInit(Lc);
    int i = 1;
    int j = 1;
    int k = 0;
    while ((i <= SeqListLength(*La)) && (j <= SeqListLength(*Lb))) {

        if (SeqListGet(*La, i) <= SeqListGet(*Lb, j)) {

            SeqListInsert(Lc, k + 1, SeqListGet(*La, i));
            k++;
            i++;

        } else {

            SeqListInsert(Lc, k + 1, SeqListGet(*Lb, j));
            k++;
            j++;
        }
    }
    while (i <= SeqListLength(*La)) {

        SeqListInsert(Lc, k + 1, SeqListGet(*La, i));
        k++;
        i++;
    }

    while (j <= SeqListLength(*Lb)) {

        SeqListInsert(Lc, k + 1, SeqListGet(*Lb, j));
        k++;
        j++;
    }

}
void ListUnion(SeqList* La, SeqList* Lb)
{
    int n = SeqListLength(*La);
    for (int i = 1; i <= SeqListLength(*Lb); ++i) {
        ElemType x = SeqListGet(*Lb, i);
        if(SeqlistLocate(*La, x)==0)
        {
            SeqListInsert(La, n+1, x);
            n++;
        }
    }
}

//������
void SeqListSort(SeqList *L) {
    for (int i = 0; i < L->length - 1; ++i) {
        for (int j = i + 1; j < L->length; ++j) {
            if (L->data[i] > L->data[j]) {
                ElemType tmp;
                tmp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = tmp;
            }
        }
    }
}



