
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tools.h"

int main() {
    srand((unsigned int)time(NULL));
    printf("----------------------program start -----------------------\n");
    readData();
    printf("----------------------program  end ------------------------\n");
    system("pause");
    return 0;
}
