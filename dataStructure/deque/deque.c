//
// Created by 홍창섭 on 2022/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

LinkedDeque* createLinkedDeque(){
    LinkedDeque *pReturn = NULL;
    pReturn = (LinkedDeque *) malloc(sizeof(LinkedDeque));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedDeque));
    } else{
        printf("Error in createLinkedDeque()\n");
        return NULL;
    }
    return pReturn;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element){
    int ret = FALSE;
    DequeNode *pNode = NULL;
    if (pDeque != NULL) {
        pNode = (DequeNode *) malloc(sizeof(DequeNode));
        if (pNode != NULL) {
            *pNode = element;
            pNode->pLLink = NULL;
            pNode->pRLink = NULL;
            if (isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            } else {
                pDeque->pFrontNode->pLLink = pNode;
                pNode->pRLink = pDeque->pFrontNode;
                pDeque->pFrontNode = pNode;
            }
            pDeque->currentElementCount++;
            ret = TRUE;
        }
    } else {
        printf("error in insertFrontLD()\n");
    }
    return ret;
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element){
    int ret = FALSE;
    DequeNode *pNode = NULL;
    if (pDeque != NULL) {
        pNode = (DequeNode *) malloc(sizeof(DequeNode));
        if (pNode != NULL) {
            *pNode = element;
            pNode->pRLink = NULL;
            pNode->pLLink = NULL;
            if (isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            } else {
                pDeque->pRearNode->pRLink = pNode;
                pNode->pLLink = pDeque->pRearNode;
                pDeque->pRearNode = pNode;
            }
            pDeque->currentElementCount++;
            ret = TRUE;
        } else {
            printf("error in insertRearLD()\n");
        }
    }
    return ret;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque){
    DequeNode *pReturn = NULL;
    if (pDeque != NULL) {
        if (isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pFrontNode;
            pDeque->pFrontNode = pReturn->pRLink;
            pReturn->pRLink = NULL;

            pDeque->currentElementCount--;
            if (isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pRearNode = NULL;
            } else {
                pDeque->pFrontNode->pLLink = NULL;
            }
        }
    }
    return pReturn;
}

DequeNode* peekFrontLD(LinkedDeque* pDeque){
    DequeNode *pReturn = NULL;
    if (pDeque != NULL) {
        if (isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pFrontNode;
        }
    }
    return pReturn;
}

DequeNode* deleteRearLD(LinkedDeque* pDeque){
    DequeNode *pReturn = NULL;
    if (pDeque != NULL) {
        if (isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pRearNode;
            pDeque->pRearNode = pReturn->pLLink;
            pReturn->pLLink = NULL;

            pDeque->currentElementCount--;
            if (isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pFrontNode = NULL;
            } else {
                pDeque->pRearNode->pRLink = NULL;
            }
        }
    }
    return pReturn;
}

DequeNode* peekRearLD(LinkedDeque* pDeque){
    DequeNode *pReturn = NULL;
    if (pDeque != NULL) {
        if (isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pRearNode;
        }
    }
    return pReturn;
}

void deleteLinkedDeque(LinkedDeque* pDeque){
    DequeNode *pNode = NULL;
    DequeNode *pDelNode = NULL;

    if (pDeque != NULL) {
        pNode = pDeque->pFrontNode;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pRLink;
            free(pDelNode);
        }
        free(pDeque);
    }
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
    return FALSE;
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    int ret = FALSE;
    if (pDeque != NULL) {
        if (pDeque->currentElementCount == 0) {
            ret = TRUE;
        }
    }

    return ret;
}