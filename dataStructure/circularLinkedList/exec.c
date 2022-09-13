//
// Created by 홍창섭 on 2022/09/13.
//

#include <stdio.h>
#include "circularlist.h"

int main(int argc, char* argv[])
{
    int i = 0;
    int arrayCount = 0;
    CircularList* pList = NULL;
    CircularListNode* pValue = NULL;
    CircularListNode node;


    pList = createCircularList(6);
    if (pList != NULL)
    {
        node.data = 1;
        addElement(pList, 0, node);

        node.data = 3;
        addElement(pList, 1, node);

        node.data = 5;
        addElement(pList, 2, node);
        displayCircularList(pList);

        removeElement(pList, 0);
        arrayCount = getCircularListLength(pList);
        for (i = 0; i < arrayCount; i++)
        {
            pValue = getElement(pList, i);
            printf("position[%d] : %d\n", i, pValue->data);
        }

        deleteCircularList(pList);
    }

    return 0;
}
