//
// Created by 홍창섭 on 2022/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount){
    ArrayMaxHeap *pReturn = NULL;
    int i= 0;

    if (maxElementCount > 0) {
        pReturn = (ArrayMaxHeap *) malloc(sizeof(ArrayMaxHeap));
        if (pReturn != NULL) {
            pReturn->maxElementCount = maxElementCount;
            pReturn->currentElementCount = 0;
            pReturn->pElement = (HeapNode *) malloc(sizeof(HeapNode) * (maxElementCount + 1));
            if (pReturn->pElement == NULL) {
                printf("error - malloc() HeapNode in createArrayMaxHeap()\n");
                free(pReturn);
                return NULL;
            }
            memset(pReturn->pElement,0,sizeof (HeapNode)* (maxElementCount + 1));
        }
    } else{
        printf("error - in malloc ArrayMaxHeap in createArrayMaxHeap()\n");
    }
    return pReturn;
}

void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element){
    int i = 0;

    if (pArrayHeap != NULL) {
        if (pArrayHeap->currentElementCount == pArrayHeap->maxElementCount) {
            printf("Heap Full Error in insertMaxHeapAH()\n");
            return;
        }
        pArrayHeap->currentElementCount++;
        i = pArrayHeap->currentElementCount;

        while ((i != 1) && (element.key > pArrayHeap->pElement[i / 2].key)) {
            pArrayHeap->pElement[i] = pArrayHeap->pElement[i / 2];
            i /= 2;
        }
        pArrayHeap->pElement[i] = element;
    }
}

HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap){
    HeapNode *pReturn = NULL;
    HeapNode *pTemp = NULL;

    int i = 0;
    int parent = 0, child = 0;

    if (pArrayHeap != NULL && pArrayHeap->currentElementCount > 0) {
        pReturn = (HeapNode *) malloc(sizeof(HeapNode));
        if (pReturn == NULL) {
            printf("error in HeadNode allocation deleteArrayMaxHeap()\n");
            return NULL;
        }
        //Step1 : 루트 노드가 반환되는 지점
        *pReturn = pArrayHeap->pElement[1];
        //i : 힙의 제일 마지막 위치 인덱스
        //pTemp : 힙의 제일 마지막 노드를 가르킴
        i = pArrayHeap->currentElementCount;
        pTemp = &(pArrayHeap->pElement[i]);
        pArrayHeap->currentElementCount--;//현재 노드 개수 하나 감소
        //while문이 시작되는 곳은 루트 노드와 루트 노드의 왼쪽 자식
        parent = 1;
        child = 2;
        //힙의 제일 마지막 위치에 있는 노드를 만날때 까지 반복
        while (child <= pArrayHeap->currentElementCount) {
            //오른쪽 자식이 왼쪽보다 클 경우 오른쪽으로 이동(부모가 홀수번째로 변경될 예정)
            if ((child < pArrayHeap->currentElementCount) &&
                pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key) {
                child++;
            }
            if (pTemp->key >= pArrayHeap->pElement[child].key) {
                break;
            }
            pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
            parent = child;
            child *= 2;
        }
        pArrayHeap->pElement[parent] = *pTemp;
    }
    return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap){
    if (pArrayHeap != NULL) {
        if (pArrayHeap->pElement != NULL) {
            free(pArrayHeap->pElement);
        }
        free(pArrayHeap);
    }
}

