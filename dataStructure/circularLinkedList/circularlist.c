//
// Created by 홍창섭 on 2022/09/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlist.h"

CircularList* createCircularList(){
    CircularList *pReturn = NULL;
    int i = 0;

    pReturn = (CircularList *) malloc(sizeof(CircularList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(CircularList));
    } else {
        printf("error in createCircularList() \n");
        return NULL;
    }
    return pReturn;
}

int addElement(CircularList* pList, int position,CircularListNode element){
    int ret = FALSE;
    int i = 0;
    CircularListNode *pPreNode = NULL,*pNewNode = NULL,*pLastNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (CircularListNode *) malloc(sizeof(CircularListNode));
            if (pNewNode == NULL) {
                printf("error in addElement() \n");
                return ret;
            }
            *pNewNode = element;
            pNewNode->pLink = NULL;

            /*
             * 추가할 위치가 첫번째 index인 경우
             * */
            if (position == 0) {
                /*
                 * 현재 노드가 하나도 없는 경우
                 * */
                if (pList->currentElementCount == 0) {
                    pList->pLink = pNewNode;
                }else{
                    pLastNode = pList->pLink;//첫번째 헤더부터 마지막 노드까지 탐색
                    while (pLastNode->pLink != pList->pLink) {
                        pLastNode = pLastNode->pLink;
                    }
                    pList->pLink = pNewNode;//리스트의 첫번째 노드를 새롭게 할당
                    pNewNode->pLink = pLastNode->pLink;//기존의 첫번째 노드를 새로운 첫번째 노드에 연결
                    pLastNode->pLink = pNewNode;
                }
            }
            //추가하려는 위치가 첫번째 index가 아닌 경우
            else{
                pPreNode = pList->pLink;
                //추가하려는 인덱스 바로 전까지 노드 탐색
                for (i = 0; i < position-1; i++) {
                    pPreNode = pPreNode->pLink;
                }
                pNewNode->pLink = pPreNode->pLink;
                pPreNode->pLink = pNewNode;
            }
            pList->currentElementCount++;
            ret = TRUE;
        } else{
            printf("error in addElement() \n");
        }
    }
    return ret;
}

int removeElement(CircularList* pList,int position){
    int ret = FALSE;

    int i = 0, arrayCount = 0;
    CircularListNode *pPreNode = NULL, *pDelNode = NULL, *pLastNode = NULL;

    if (pList != NULL) {
        arrayCount = getCircularListLength(pList);
        if (position >= 0 && position < arrayCount) {
            if (position == 0) {
                pDelNode = pList->pLink;//첫번째 노드
                /*
                 * 리스트에 요소가 하나만 남아있는 경우
                 * */
                if (arrayCount == 1) {
                    free(pDelNode);
                    pList->pLink = NULL;//공백 리스트
                } else{
                    pLastNode = pList->pLink;
                    while (pLastNode->pLink != pList->pLink) {
                        pLastNode = pLastNode->pLink;
                    }
                    pLastNode->pLink = pDelNode->pLink;
                    pList->pLink = pDelNode->pLink;
                    free(pDelNode);
                }
            } else{
                pPreNode = pList->pLink;
                for (i = 0; i < position - 1; i++) {
                    pPreNode = pPreNode->pLink;
                }
                pDelNode = pPreNode->pLink;
                pPreNode->pLink = pDelNode->pLink;
                free(pDelNode);
            }
            pList->currentElementCount--;
            ret = TRUE;
        } else{
            printf("index error in removeElement() \n");
        }
    }
    return ret;
}

CircularListNode* getElement(CircularList* pList,int position){
    int i = 0;
    CircularListNode *pNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            pNode = pList->pLink;
            for (i = 0; i < position; i++) {
                pNode = pNode->pLink;
            }
        }
    }
    return pNode;
}

void displayCircularList(CircularList* pList){
    int i = 0;
    if (pList != NULL) {
        printf("현재 원소 개수 : %d\n", pList->currentElementCount);
        for (i = 0; i < pList->currentElementCount; i++) {
            printf("[%d] : %d\n", i, getElement(pList, i)->data);
        }
    } else{
        printf("No element\n");
    }
}

int getCircularListLength(CircularList* pList){
    int ret = 0;
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}

void deleteCircularList(CircularList* pList){
    int i = 0;
    if (pList != NULL) {
        clearCircularList(pList);
        free(pList);
    }
}

void clearCircularList(CircularList* pList){
    if (pList != NULL) {
        while (pList->currentElementCount > 0) {
            removeElement(pList, 0);
        }
    }
}
