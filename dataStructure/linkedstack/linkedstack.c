//
// Created by 홍창섭 on 2022/09/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

LinkedStack* createLinkedStack(){
    LinkedStack *pReturn = NULL;
    pReturn = (LinkedStack *) malloc(sizeof(LinkedStack));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedStack));
    } else{
        printf("error in createLinkedStack()\n");
        return NULL;
    }
    return pReturn;
}

int push(LinkedStack* pStack,StackNode element){
    int ret = FALSE;
    StackNode *pNode = NULL;

    if (pStack != NULL) {
        pNode = (StackNode *) malloc(sizeof(StackNode));
        if (pNode != NULL) {
            memset(pNode, 0, sizeof(StackNode));
            *pNode = element;
            pNode->pLink = pStack->pTopElement;//기존에 있던 top 노드로 연결
            pStack->pTopElement = pNode;
            pStack->currentElementCount++;
            ret = TRUE;
        }else{
            printf("error in pNode \n");
        }
    }
    return ret;
}

StackNode* pop(LinkedStack* pStack){
    StackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->pTopElement;//Top을 반환
            pStack->pTopElement = pReturn->pLink;
            pReturn->pLink = NULL;
            pStack->currentElementCount--;
        }
    }
    return pReturn;
}

StackNode* peek(LinkedStack* pStack){
    StackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->pTopElement;
        }
    }
    return pReturn;
}

/*
 * Stack 자체를 없애는 메서드
 * */
void deleteLinkedStack(LinkedStack *pStack){
    StackNode *pNode = NULL;
    StackNode *pDelNode = NULL;

    if (pStack != NULL) {
        pNode = pStack->pTopElement;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pStack);
    }
}

int isLinkedStackFull(LinkedStack *pStack){
    return FALSE;
}

int isLinkedStackEmpty(LinkedStack *pStack){
    int res = FALSE;
    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            res = TRUE;
        }
    }
    return res;
}

void displayLinkedStack(LinkedStack *pStack)
{
    StackNode *pNode = NULL;
    int i = 1;
    if (pStack != NULL) {
        printf("현재 노드 개수 : %d\n",
               pStack->currentElementCount);
        pNode = pStack->pTopElement;
        while(pNode != NULL) {
            printf("[%d]-[%c]\n",pStack->currentElementCount - i,pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}