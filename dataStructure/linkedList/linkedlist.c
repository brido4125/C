//
// Created by 홍창섭 on 2022/09/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList *createLinkedList(){
    LinkedList *pReturn = NULL;

    int i = 0;

    pReturn = (LinkedList *) malloc(sizeof(LinkedList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedList));
    } else{
        printf("메모리 할당 오류 createLinkedList() \n");
        return NULL;
    }
    return pReturn;
}

int addElement(LinkedList *pList, int position, ListNode element){
    int ret = FALSE;
    int i = 0;
    ListNode *pPreNode = NULL;
    ListNode *pNewNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (ListNode *) malloc(sizeof(ListNode));
            if (pNewNode != NULL) {
                *pNewNode = element;
                pNewNode->pLink = NULL;

                /*
                 * LinkedList의 경우 데이터의 삽입 및 삭제가 유리함
                 * 데이터를 좌우로 밀어주는 과정이 필요 없음
                 * position까지 링크를 타고 찾아가야하는 과정 필요 => index 검색에 불리
                 * */
                pPreNode = &(pList->headerNode);
                for (i = 0; i < position; i++) {
                    pPreNode = pPreNode->pLink;
                }

                pNewNode->pLink = pPreNode->pLink;
                pPreNode->pLink = pNewNode;

                pList->currentElementCount++;

                ret = TRUE;
            }
            else{
                printf("error in addElement() \n");
                return ret;
            }
        } else{
            printf("error in addElement() \n");
        }
    }
    return ret;
}

int removeLLElement(LinkedList* pList, int position){
    int ret = FALSE;
    int i = 0;
    int arrayCount = 0;
    ListNode* pNode = NULL;
    ListNode *pDelNode = NULL;
    if (pList != NULL) {
        arrayCount = getLinkedListLength(pList);
        if (position >= 0 && position < arrayCount) {
            pNode = &(pList->headerNode);//탐색을 위한 헤더노드 설정
            for (i = 0; i < position; i++) {
                pNode = pNode->pLink;
            }
            pDelNode = pNode->pLink;
            pNode->pLink = pDelNode->pLink;
            free(pDelNode);
            pList->currentElementCount--;
            ret = TRUE;
        } else{
            printf("error in removeLLElement() \n");

        }
    }
    return ret;
}

ListNode* getLLElement(LinkedList* pList, int position){
    ListNode *pReturn = NULL;
    int i = 0;
    ListNode *pNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            pNode = &(pList->headerNode);
            for (i = 0; i < position; i++) {
                pNode = pNode->pLink;
            }
            pReturn = pNode->pLink;
        }
    }
    return pReturn;
}

void deleteLinkedList(LinkedList* pList){
    int i = 0;
    if (pList != NULL) {
        clearLinkedList(pList);
        free(pList);
    }
}

void clearLinkedList(LinkedList* pList){
    int i = pList->currentElementCount-1;
    while (i >= 0) {
        removeLLElement(pList, i);
        i--;
    }
}

int getLinkedListLength(LinkedList* pList){
    int ret = 0;

    if (pList != NULL) {
        ret = pList->currentElementCount;
    }

    return ret;
}

int isEmpty(LinkedList *pList){
    int ret = FALSE;

    if (pList != NULL) {
        if (pList->currentElementCount == 0) {
            ret = TRUE;
        }
    }

    return ret;
}
