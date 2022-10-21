//
// Created by 홍창섭 on 2022/09/16.
//

#ifndef DATASTRUCTURE_LINKEDQUEUE_H
#define DATASTRUCTURE_LINKEDQUEUE_H

#define TRUE		1
#define FALSE		0

typedef struct QueueNodeType {
    char data;
    struct QueueNodeType* pLink;
}QueueNode;

typedef struct LinkedQueueType{
    int currentElement;
    QueueNode* frontNode; // 제일 앞단 pop하면 나오는 Node
    QueueNode* rearNode; // Queue의 제일 뒷단, push 할 경우 들어가는 Node
}LinkedQueue;

LinkedQueue* createLinkedQueue();
int offer(LinkedQueue* pQueue, QueueNode element);
QueueNode* poll(LinkedQueue* pQueue);
QueueNode* peek(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueFull(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);
void displayQueue(LinkedQueue* pQueue);

#endif //DATASTRUCTURE_LINKEDQUEUE_H
