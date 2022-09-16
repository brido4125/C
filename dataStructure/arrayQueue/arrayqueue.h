//
// Created by 홍창섭 on 2022/09/16.
//

#ifndef DATASTRUCTURE_ARRAYQUEUE_H
#define DATASTRUCTURE_ARRAYQUEUE_H

#define TRUE		1
#define FALSE		0

typedef struct ArrayQueueNodeType{
    char data;
}ArrayQueueNode;

typedef struct ArrayQueueType{
    int maxElementCount;
    int currentElementCount;
    int front;
    int rear;
    ArrayQueueNode *pElement;
}ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount);
int offer(ArrayQueue* pQueue, ArrayQueueNode element);//리어쪽으로 노드 푸쉬
ArrayQueueNode* poll(ArrayQueue* pQueue);//프론트쪽으로 노드 꺼내기, 큐에서 완전히 삭제
ArrayQueueNode *peek(ArrayQueue* pQueue);//제일 앞 노드(가장 프론트) 노드 읽어오기
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);
void displayArrayQueue(ArrayQueue *pQueue);


#endif //DATASTRUCTURE_ARRAYQUEUE_H
