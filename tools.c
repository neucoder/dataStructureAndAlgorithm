//
// Created by ys on 2019/4/7.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int randint(int minVal, int maxVal)
{
    int r;

    r = minVal + rand()%(maxVal - minVal + 1);
    return r;
}

