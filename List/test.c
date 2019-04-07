#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "../tools.h"

void testSeqList() {
    SeqList Lc, La, Lb;
    //��ʼ��
    SeqListInit(&La);
    SeqListInit(&Lb);
    SeqListInit(&Lc);
    printf("La length:%d\n", La.length);

    for (int i = 0; i < 25; ++i) {
        La.data[i] = randint(0, 100);
        La.length++;
    }

    for (int i = 0; i < 25; ++i) {
        Lb.data[i] = randint(0, 100);
        Lb.length++;
    }

    puts("����֮ǰ");
    SeqListTravel(La);
    SeqListTravel(Lb);
    //���Ա���ϲ�
    SeqListSort(&La);
    SeqListSort(&Lb);
    puts("����ϲ�֮ǰ,�����");
    SeqListTravel(La);
    SeqListTravel(Lb);
    ListMerge(&La, &Lb, &Lc);
    puts("����ϲ�֮��");
    SeqListTravel(La);
    SeqListTravel(Lb);
    SeqListTravel(Lc);


    //���Ը�������
    /* SeqListTravel(La);
     printf("La �ĵ�3��Ԫ��%d\n", SeqListGet(La, 3));
     SeqListInsert(&La, 3, 13);
     puts("����Ԫ��13");
     SeqListTravel(La);
     printf("13��ǰ���ǣ�%d\n",SeqListPrior(La,13));
     printf("13�ĺ���ǣ�%d\n",SeqListNext(La,13));
     printf("13��λ���ǣ�%d\n",SeqlistLocate(La,13));
     printf("La�ĳ����ǣ�%d\n",SeqListLength(La));
     if(SeqListEmpty(La))
     {
         puts("La �ǿյ�");
     } else{
         puts("La �Ƿǿյ�");
     }
     SeqListDel(&La, 4);
     puts("ɾ�����ĸ�λ�õ�Ԫ��");
     SeqListTravel(La);
     puts("La Lb�ϲ���һ��");
     puts("�ϲ�֮ǰ��La��Lb");
     SeqListTravel(La);
     SeqListTravel(Lb);
     ListUnion(&La, &Lb);
     puts("�ϲ�֮���La��Lb");
     SeqListTravel(La);
     SeqListTravel(Lb);*/


}

