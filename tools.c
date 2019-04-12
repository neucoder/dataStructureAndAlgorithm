//
// Created by ys on 2019/4/7.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
//����һ��������� ��ΧminVal-maxVal

int randint(int minVal, int maxVal)
{
    int r;
    r = minVal + rand()%(maxVal - minVal + 1);
    return r;
}


//����ָ�����
void swap(int **a, int **b)
{
    int tmp;
    tmp = **a;
    **a = **b;
    **b = tmp;
}

//���Խ���ָ������
void testSwap()
{
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    *a = 3;
    *b = 5;
    printf("*a:%d and *b:%d\n", *a, *b);
    swap(&a, &b);
    printf("*a:%d and *b:%d\n", *a, *b);

}

void readFile()
{
    int ch;//�����ļ�����ָ��
    FILE *fp;//�ж��������Ƿ���ȷ
    fp = fopen("../abctest.txt","r");

    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}


void readData()
{
    FILE *fp;
    fp = fopen("../data/1000000.csv","r");
    int a[100000];

    for (int i = 0; i < 100000; ++i) {
        fscanf(fp,"%d,",&a[i]);
//        printf("%d\t",a[i]);
//        if((i+1)%10==0)
//        {
//            printf("\n");
//        }
    }
    fclose(fp);
    int start = clock();
    bubbleSort(a, 100000);
    int end = clock();
    for (int i = 0; i < 100000; ++i) {

        printf("%d\t",a[i]);
        if((i+1)%10==0)
        {
            printf("\n");
        }
    }

    printf("������ʱ%dms",end-start);
}


//ð������
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                int tmp;
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}





