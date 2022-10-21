//
// Created by 홍창섭 on 2022/10/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

int offerCharData(LinkedQueue* pQueue,char data){
    QueueNode node = {0};
    node.data = data;
    return offer(pQueue, node);
}

int main(void){
    LinkedQueue *pQueue = NULL;
    QueueNode *pNode = NULL;
    char value = 0;

    pQueue = createLinkedQueue();
    if (pQueue != NULL) {
        offerCharData(pQueue, 'A');
        offerCharData(pQueue, 'B');
        offerCharData(pQueue, 'C');
        offerCharData(pQueue, 'D');
        displayQueue(pQueue);
    }
}