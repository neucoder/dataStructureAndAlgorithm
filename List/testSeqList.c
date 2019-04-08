#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "../tools.h"

void testSeqList() {
    SeqList Lc, La, Lb;
    //初始化
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

    puts("排序之前");
    SeqListTravel(La);
    SeqListTravel(Lb);
    //测试保序合并
    SeqListSort(&La);
    SeqListSort(&Lb);
    puts("保序合并之前,排序后");
    SeqListTravel(La);
    SeqListTravel(Lb);
    ListMerge(&La, &Lb, &Lc);
    puts("保序合并之后");
    SeqListTravel(La);
    SeqListTravel(Lb);
    SeqListTravel(Lc);


    //测试个个函数
    /* SeqListTravel(La);
     printf("La 的第3个元素%d\n", SeqListGet(La, 3));
     SeqListInsert(&La, 3, 13);
     puts("插入元素13");
     SeqListTravel(La);
     printf("13的前驱是：%d\n",SeqListPrior(La,13));
     printf("13的后继是：%d\n",SeqListNext(La,13));
     printf("13的位置是：%d\n",SeqlistLocate(La,13));
     printf("La的长度是：%d\n",SeqListLength(La));
     if(SeqListEmpty(La))
     {
         puts("La 是空的");
     } else{
         puts("La 是非空的");
     }
     SeqListDel(&La, 4);
     puts("删除第四个位置的元素");
     SeqListTravel(La);
     puts("La Lb合并在一起");
     puts("合并之前的La，Lb");
     SeqListTravel(La);
     SeqListTravel(Lb);
     ListUnion(&La, &Lb);
     puts("合并之后的La，Lb");
     SeqListTravel(La);
     SeqListTravel(Lb);*/


}

