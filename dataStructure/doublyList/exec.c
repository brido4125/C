//
// Created by 홍창섭 on 2022/09/13.
//

#include <stdio.h>
#include "doublylist.h"

int main(int argc, char *argv[])
{
    DoublyList *pList = NULL;
    DoublyListNode *pValue = NULL;
    DoublyListNode node;

    pList = createDoublyList();
    if (pList != NULL)
    {
        node.data = 1;
        addElement(pList, 0, node);
        node.data = 3;
        addElement(pList, 1, node);
        node.data = 5;
        addElement(pList, 2, node);
        displayDoublyList(pList);

        removeElement(pList, 0);
        displayDoublyList(pList);

        deleteDoublyList(pList);
    }

    return 0;
}
