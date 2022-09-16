//
// Created by 홍창섭 on 2022/09/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

int main(int argc, char *argv[])
{
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;

    pStack = createLinkedStack();
    if (pStack != NULL) {
        StackNode node1 = {'A'};
        StackNode node2 = {'B'};
        StackNode node3 = {'C'};
        StackNode node4 = {'D'};

        push(pStack, node1);
        push(pStack, node2);
        push(pStack, node3);
        push(pStack, node4);
        displayLinkedStack(pStack);

        pNode = pop(pStack);
        if (pNode != NULL)
        {
            printf("Pop-[%c]\n", pNode->data);
            free(pNode);
        }
        else {
            printf("Pop-NULL\n");
        }
        displayLinkedStack(pStack);

        pNode = peek(pStack);
        if (pNode != NULL) {
            printf("Peek-[%c]\n", pNode->data);
        }
        else {
            printf("Peek-NULL\n");
        }
        displayLinkedStack(pStack);

        deleteLinkedStack(pStack);
    }
    return 0;
}
