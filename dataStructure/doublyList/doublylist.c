//
// Created by 홍창섭 on 2022/09/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"

DoublyList* createDoublyList(){
    DoublyList *pReturn = NULL;

    pReturn = (DoublyList *) malloc(sizeof(DoublyList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(DoublyList));
        pReturn->headerNode.lLink = &(pReturn->headerNode);
        pReturn->headerNode.rLink = &(pReturn->headerNode);
    } else{
        printf("error in createDoublyList()\n");
        return NULL;
    }
    return pReturn;
}

int addElement(DoublyList* pList, int position, DoublyListNode element){
    int ret = FALSE;
    DoublyListNode *privNode = NULL, *newNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            newNode = (DoublyListNode *) malloc(sizeof(DoublyListNode));
            if (newNode == NULL) {
                printf("error in addElement()\n");
                return ret;
            }
            *newNode = element;
            newNode->rLink = NULL;
            newNode->lLink = NULL;

            privNode = &(pList->headerNode);
            for (int i = 0; i < position - 1; i++) {
                privNode = privNode->rLink;
            }

            newNode->lLink = privNode;
            newNode->rLink = privNode->rLink;
            privNode->rLink = newNode;
            newNode->rLink->lLink = newNode;

            pList->currentElementCount++;
            ret = TRUE;
        } else{
            printf("error in position index by addElement()\n");
        }
    }
    return ret;
}

int removeElement(DoublyList* pList, int position){
    int ret = FALSE;
    int arrayCount = 0;
    DoublyListNode *pPreNode = NULL, *pDelNode = NULL;

    if (pList != NULL) {
        arrayCount = pList->currentElementCount;
        if (position >= 0 && position < arrayCount) {
            pPreNode = &pList->headerNode;
            for (int i = 0; i < position; i++) {
                pPreNode = pPreNode->rLink;
            }
            pDelNode = pPreNode->rLink;

            pPreNode->rLink = pDelNode->rLink;
            pDelNode->rLink->lLink = pPreNode;

            pList->currentElementCount--;
            ret = TRUE;
        }
        else{
            printf("error in position index by addElement()\n");
        }
    }
    return ret;
}

DoublyListNode* getElement(DoublyList* pList, int position){
    DoublyListNode *pReturn = NULL, *pNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            pNode = &pList->headerNode;
            for (int i = 0; i < position; i++) {
                pNode = pNode->rLink;
            }
            pReturn = pNode->rLink;
        } else{
            printf("error in position index by getElement()\n");
        }
    }
    return pReturn;
}

void displayDoublyList(DoublyList* pList){
    if (pList != NULL) {
        printf("현재 노드 갯수 : %d\n", pList->currentElementCount);
        for (int i = 0; i < pList->currentElementCount; i++) {
            printf("[%d] : %d\n", i, getElement(pList, i)->data);
        }
    }else{
        printf("No element in this list\n");
    }
}

void deleteDoublyList(DoublyList* pList){
    if (pList != NULL) {
        clearDoublyList(pList);
        free(pList);
    }
}

void clearDoublyList(DoublyList* pList){
    if (pList != NULL) {
        while (pList->currentElementCount > 0) {
            removeElement(pList, 0);
        }
    }
}

int getDoublyListLength(DoublyList* pList){
    int ret = 0;
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}