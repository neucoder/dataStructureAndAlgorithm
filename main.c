
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tools.h"
#include "String/String.h"


int main() {
    srand((unsigned int)time(NULL));
    printf("----------------------program start -----------------------\n");
    testString();
    printf("----------------------program  end ------------------------\n");
    system("pause");
    return 0;
}
