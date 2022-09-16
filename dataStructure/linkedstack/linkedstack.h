//
// Created by 홍창섭 on 2022/09/14.
//

#ifndef DATASTRUCTURE_LINKEDSTACK_H
#define DATASTRUCTURE_LINKEDSTACK_H

typedef struct StackNodeType{
    char data;
    struct StackNodeType* pLink;
}StackNode;

typedef struct LinkedStackType{
    int currentElementCount;
    StackNode* pTopElement;
}LinkedStack;

LinkedStack* createLinkedStack();
int push(LinkedStack* pStack,StackNode element);
StackNode* pop(LinkedStack* pStack);
StackNode* peek(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayLinkedStack(LinkedStack *pStack);


#define TRUE    1
#define FALSE   0

#endif //DATASTRUCTURE_LINKEDSTACK_H
