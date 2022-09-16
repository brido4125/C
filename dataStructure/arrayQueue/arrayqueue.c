//
// Created by 홍창섭 on 2022/09/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount){
    ArrayQueue *pReturn = NULL;
    if (maxElementCount > 0) {
        pReturn = (ArrayQueue *) malloc(sizeof(ArrayQueue));
        if (pReturn != NULL) {
            memset(pReturn, 0, sizeof(ArrayQueue));
            pReturn->maxElementCount = maxElementCount;
            pReturn->front = -1;
            pReturn->rear = -1;
        }else{
            printf("pReturn memory error,createArrayQueue()\n");
            return NULL;
        }
    }else{
        printf("error maxElementCount <= 0\n");
        return NULL;
    }
    pReturn->pElement = (ArrayQueueNode *) malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if (pReturn->pElement != NULL) {
        memset(pReturn->pElement, 0, sizeof(ArrayQueueNode) * maxElementCount);
    }else{
        printf("pReturn->pElement memory error,createArrayQueue()\n");
        free(pReturn);
        return NULL;
    }
    return pReturn;
}

//offer ==> enque 라고도 함
int offer(ArrayQueue* pQueue, ArrayQueueNode element){
    int result = FALSE;
    if (pQueue != NULL) {
        if (isArrayQueueFull(pQueue) == FALSE) {
            pQueue->rear++;
            pQueue->pElement[pQueue->rear] = element;
            pQueue->currentElementCount++;
            result = TRUE;
        }else{
            printf("Fully Array Queue Error, enqueueAQ()\n");
        }
    }
    return result;
}

ArrayQueueNode* poll(ArrayQueue* pQueue){
    ArrayQueueNode *pollNode = NULL;
    if (pQueue != NULL) {
        if (isArrayQueueEmpty(pQueue) == FALSE) {
            pollNode = (ArrayQueueNode *) malloc(sizeof(ArrayQueueNode));
            if (pollNode != NULL) {
                pQueue->front++;
                pollNode->data = pQueue->pElement[pQueue->front].data;
                pQueue->currentElementCount--;
            }else{
                printf("pollNode allocation error in poll()\n");
            }
        }else{
            printf("array queue empty error in poll()\n");
        }
    }
    return pollNode;
}

ArrayQueueNode *peek(ArrayQueue* pQueue){
    ArrayQueueNode *peekNode = NULL;
    if (pQueue != NULL) {
        if (isArrayQueueEmpty(pQueue) == FALSE) {
            peekNode = &(pQueue->pElement[pQueue->front+1]);
        }
    }
    return peekNode;
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (pQueue != NULL) {
        if (pQueue->pElement != NULL) {
            free(pQueue->pElement);
        }
        free(pQueue);
    }
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    int ret = FALSE;

    if (pQueue != NULL) {
        if (pQueue->currentElementCount == pQueue->maxElementCount
            || pQueue->rear == pQueue->maxElementCount - 1) {
            ret = TRUE;
        }
    }

    return ret;
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    int ret = FALSE;

    if (pQueue != NULL) {
        if (pQueue->currentElementCount == 0) {
            ret = TRUE;
        }
    }

    return ret;
}

void displayArrayQueue(ArrayQueue *pQueue)
{
    if (pQueue != NULL) {
        printf("총 노드 개수‚: %d, 현재 노드 개수: %d\n",pQueue->maxElementCount,pQueue->currentElementCount);

        for(int i = pQueue->front + 1; i <= pQueue->rear; i++) {
            printf("[%d]-[%c]\n", i, pQueue->pElement[ i ].data);
        }
    }
}