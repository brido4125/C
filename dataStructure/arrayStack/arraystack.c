//
// Created by 홍창섭 on 2022/09/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

ArrayStack *createArrayStack(int size){
    ArrayStack *pReturn = NULL;
    if (size > 0) {
        pReturn = (ArrayStack *) malloc(sizeof(ArrayStack));
        if (pReturn != NULL) {
            memset(pReturn, 0, sizeof(ArrayStack));
            pReturn->maxElementCount = size;
        } else{
            printf("error in createArrayStack()\n");
            return NULL;
        }

        pReturn->pElement = (ArrayStackNode *) malloc(sizeof(ArrayStackNode) * size);
        if (pReturn->pElement != NULL) {
            memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);
        } else{
            printf("error in pElement createArrayStack()\n");
            free(pReturn);
            return NULL;
        }
    } else{
        printf("size error in createArrayStack()\n");
        return NULL;
    }
    return pReturn;
}

int push(ArrayStack* pStack,ArrayStackNode element){
    int ret = FALSE;
    if (pStack != NULL) {
        if (isArrayStackFull(pStack) == FALSE) {
            pStack->pElement[pStack->currentElementCount] = element;
            pStack->currentElementCount++;
            ret = TRUE;
        }else{
            printf("stack full error push()\n");
        }
    }
    return ret;
}

ArrayStackNode* pop(ArrayStack* pStack){
    ArrayStackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isArrayStackEmpty(pStack) == FALSE) {
            pReturn = (ArrayStackNode *) malloc(sizeof(ArrayStackNode));
            if (pReturn != NULL) {
                //새로운 노드를 생성하여 그 포인터를 반환 => 메모리 해제 필요
                *pReturn = pStack->pElement[pStack->currentElementCount - 1];
                pStack->currentElementCount--;
            }else{
                printf("error in memory allocation pop()\n");
            }
        } else{
            printf("empty stack error pop()\n");
        }
    }
    return pReturn;
}

ArrayStackNode* peek(ArrayStack* pStack){
    ArrayStackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isArrayStackEmpty(pStack) == FALSE) {
            //기존 노드에 대한 포인터를 전달 => 메모리 해제 필요 X
            pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
        }
    }
    return pReturn;
}

void deleteArrayStack(ArrayStack* pStack){
    if (pStack != NULL) {
        if (pStack->pElement != NULL) {
            free(pStack->pElement);
        }
        free(pStack);
    }
}

int isArrayStackFull(ArrayStack* pStack){
    int ret = FALSE;

    if (pStack != NULL) {
        if (pStack->currentElementCount == pStack->maxElementCount) {
            ret = TRUE;
        }
    }
    return ret;
}

int isArrayStackEmpty(ArrayStack* pStack){
    int ret = FALSE;

    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}

void displayArrayStack(ArrayStack* pStack){
    if (pStack != NULL) {
        int size = pStack->maxElementCount;
        int top = pStack->currentElementCount;

        printf("스택 크기 : %d, 현재 노드 개수 : %d\n", size, top);

        for (int i = size - 1; i >= top; i--) {
            printf("빈 스택 : [%d]\n", i);
        }

        for (int i = top - 1; i >= 0; i--) {
            printf("[%d]번째 데이터 = [%c]\n", i, pStack->pElement[i].data);
        }
    }
}
