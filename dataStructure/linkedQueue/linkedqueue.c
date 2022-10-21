//
// Created by 홍창섭 on 2022/09/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedqueue.h"

LinkedQueue *createLinkedQueue(){
    LinkedQueue *pReturn = NULL;

    // LinkedQueue 구조체에 대한 메모리 할당
    pReturn = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    if (pReturn != NULL) {
        memset(pReturn,0,sizeof(LinkedQueue));
    } else{
        printf("오류, 메모리 할당, createLinkedQueue()\n");
    }
    return pReturn;
}

// Queue에 삽입 시 Rear Node의 포인터만 변경하면 됨
// Queue에 Node가 있는지 없는지 분기하여 구현
int offer(LinkedQueue* pQueue,QueueNode element){
    int ret = FALSE;
    QueueNode *pNode = NULL;
    if (pQueue != NULL) {
        pNode = (QueueNode *) malloc(sizeof(QueueNode));
        if (pNode != NULL) {
            *pNode = element;
            pNode->pLink = NULL;

            if (isLinkedQueueEmpty(pQueue) == TRUE) {
                pQueue->frontNode = pNode;
                pQueue->rearNode = pNode;
            } else {
                pQueue->rearNode->pLink = pNode;
                pQueue->rearNode = pNode;
            }
            pQueue->currentElement++;
            ret = TRUE;
        } else {
            printf("오류, 메모리 할당, enqueueLQ()\n");
        }
    }
    return ret;
}

// poll : 노드가 2개 이상인 경우 or 노드가 1개인 큐
//front 노드의 포인터가 변경되어야함
QueueNode *poll(LinkedQueue *pQueue){
    QueueNode *pReturn = NULL;
    if (pQueue != NULL) {
        // 비어 있지 않아야 queue에서 노드 제거 가능
        if (isLinkedQueueEmpty(pQueue) == FALSE) {
            pReturn = pQueue->frontNode;
            pQueue->frontNode = pQueue->frontNode->pLink;
            pReturn->pLink = NULL;

            pQueue->currentElement--;

            if (isLinkedQueueEmpty(pQueue) == TRUE) {
                pQueue->rearNode = NULL;
            }
        } else {
            printf("error, 빈 큐에서 poll을 수행할 수 없습니다.\n");
        }
    }
    return pReturn;
}

QueueNode* peek(LinkedQueue* pQueue){
    QueueNode *pReturn = NULL;
    if (pQueue != NULL) {
        if (isLinkedQueueEmpty(pQueue) == FALSE) {
            pReturn = pQueue->frontNode;
        }
    }
    return pReturn;
}

void deleteLinkedQueue(LinkedQueue* pQueue){
    QueueNode *pNode = NULL;
    QueueNode *pDelNode = NULL;

    if (pQueue != NULL) {
        pNode = pQueue->frontNode;
        //pNode가 NULL 값이면 모든 노드가 전부 NULL 처리된것, 그러면 while 탈출
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pQueue);
    }
}

int isLinkedQueueFull(LinkedQueue* pQueue){
    int ret = FALSE;
    return ret;
}

int isLinkedQueueEmpty(LinkedQueue *pQueue){
    int ret = FALSE;
    if (pQueue != NULL) {
        if (pQueue->currentElement == 0) {
            ret = TRUE;
        }
    }
    return ret;
}

void displayQueue(LinkedQueue* pQueue){
    QueueNode *pNode = NULL;
    int i = 0;
    if (pQueue != NULL) {
        printf("현재 큐의 노드 개수 : %d\n", pQueue->currentElement);
        pNode = pQueue->frontNode;
        while (pNode != NULL) {
            printf("[%d]-[%c]\n", i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}
