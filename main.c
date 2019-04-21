
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tools.h"
#include "Tree/BinTree.h"
#include "Tree/HFTree.h"
#include "Graph/AdjLinkedList.h"
#include "Graph/AdjGraph.h"


int main() {
    srand((unsigned int)time(NULL));
    printf("----------------------program start -----------------------\n");

    testHFCode();
    //newline
    printf("\n----------------------program  end ------------------------\n");
    system("pause");
    return 0;
}

