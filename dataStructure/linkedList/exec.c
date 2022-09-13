//
// Created by 홍창섭 on 2022/09/13.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void displayLinkedList(LinkedList* pList) {
    int i = 0;
    if (pList != NULL) {
        printf("current element number : %d \n", pList->currentElementCount);

        for (i = 0; i < pList->currentElementCount; i++) {
            printf("[%d] : %d \n", i, getLLElement(pList, i)->data);
        }

    }
    else {
        printf("Empty Linked-List \n");
    }
}

int main(int argc, char* argv[]) {
    int i = 0;
    int arrayCount = 0;
    LinkedList* pList = NULL;
    ListNode* pNode = NULL;
    ListNode node;

    pList = createLinkedList();
    if (pList != NULL) {

        node.data = 1;
        addElement(pList, 0, node);

        node.data = 3;
        addElement(pList, 1, node);

        node.data = 5;
        addElement(pList, 2, node);
        displayLinkedList(pList);

        clearLinkedList(pList);
        displayLinkedList(pList);

        deleteLinkedList(pList);
    }
    return 0;
}