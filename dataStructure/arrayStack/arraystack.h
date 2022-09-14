//
// Created by 홍창섭 on 2022/09/14.
//

#ifndef DATASTRUCTURE_ARRAYSTACK_H
#define DATASTRUCTURE_ARRAYSTACK_H

#define TRUE    1
#define FALSE   0

typedef struct ArrayStackNodeType {
    char data;
} ArrayStackNode;

typedef struct ArrayStackType{
    int maxElementCount; //최대 원소 개수
    int currentElementCount;
    ArrayStackNode *pElement;
}ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int push(ArrayStack* pStack,ArrayStackNode element);
ArrayStackNode* pop(ArrayStack* pStack);
ArrayStackNode* peek(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
void displayArrayStack(ArrayStack* pStack);

#endif //DATASTRUCTURE_ARRAYSTACK_H
