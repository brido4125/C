//
// Created by 홍창섭 on 2022/09/14.
//

#include <stdio.h>
#include "arraystack.h"

int main(int argc, char *argv[])
{
    ArrayStack *pStack = NULL;

    pStack = createArrayStack(6);
    if (pStack != NULL) {
        ArrayStackNode node1 = {'A'};
        ArrayStackNode node2 = {'B'};
        ArrayStackNode node3 = {'C'};
        ArrayStackNode node4 = {'D'};

        push(pStack, node1);
        push(pStack, node2);
        push(pStack, node3);
        push(pStack, node4);
        displayArrayStack(pStack);

        pop(pStack);
        displayArrayStack(pStack);

        peek(pStack);
        displayArrayStack(pStack);

        deleteArrayStack(pStack);
    }
    return 0;
}
