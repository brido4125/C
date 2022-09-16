//
// Created by 홍창섭 on 2022/09/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"


int enqueueAQChar(ArrayQueue* pQueue, char data)
{
    ArrayQueueNode node = {0,};
    node.data = data;
    return offer(pQueue, node);
}

int main(int argc, char *argv[])
{
    ArrayQueue *pQueue = NULL;
    ArrayQueueNode *pNode = NULL;

    pQueue = createArrayQueue(4);
    if (pQueue != NULL) {
        enqueueAQChar(pQueue, 'A');
        enqueueAQChar(pQueue, 'B');
        enqueueAQChar(pQueue, 'C');
        enqueueAQChar(pQueue, 'D');
        displayArrayQueue(pQueue);

        pNode = poll(pQueue);
        if (pNode != NULL) {
            printf("Dequeue Value-[%c]\n",
                   pNode->data);
            free( pNode );
        }
        displayArrayQueue(pQueue);

        pNode = peek(pQueue);
        if (pNode != NULL) {
            printf("Peek Value-[%c]\n",pNode->data);
        }
        displayArrayQueue(pQueue);

        enqueueAQChar(pQueue, 'E');

        displayArrayQueue(pQueue);
    }
    return 0;
}
