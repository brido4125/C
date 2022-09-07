//
// Created by 홍창섭 on 2022/09/07.
//
#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(void){
    int i = 0;
    int arrayCount = 0;
    ArrayList *pList = NULL;
    ArrayListNode *pValue = NULL;

    pList = createArrayList(6);
    if (pList != NULL) {
        ArrayListNode node;

        node.data = 1;
        addALElement(pList, 0, node);

        node.data = 3;
        addALElement(pList, 1, node);

        node.data = 4;
        addALElement(pList, 0, node);
        displayArrayList(pList);
    }
}