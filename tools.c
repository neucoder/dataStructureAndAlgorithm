//
// Created by ys on 2019/4/7.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"




//extern FILE *fp;


/*
 *
 * ������ļ�
 * FILE *fp;
    time_t t;
    fp = fopen("log.txt","a");

    fprintf(fp,"��ù���%d\n",123);
    fclose(fp);

 *
 *
 */

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

/*
void testFp()
{
    fp = fopen("log.txt","a");
    fprintf(fp,"hello,world file:%s fun:%s line:%d\n",__FILE__, __FUNCTION__, __LINE__);
    fclose(fp);
}


*/

void printDebug()
{
    printf("debug.........\n");
}


void printToFile(char *fname, ElemType *arr, int arrLen)
{
    FILE *fp;
    fp = fopen(fname, "w");
    for (int j = 1; j <= arrLen ; ++j) {
        fprintf(fp, "%10d", arr[j]);
        if((j % 10)==0)
        {
            fprintf(fp, "\n");

        }
    }
    fclose(fp);
}


void testRand()
{
    for (int i = 1; i <= 20; ++i) {
        printf("%8d",randint(1,10000));
        if((i%10)==0)
        {
            printf("\n");
        }
    }
}