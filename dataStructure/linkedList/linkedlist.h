//
// Created by 홍창섭 on 2022/09/13.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

typedef struct ListNodeType{
    int data;
    struct ListNodeType* pLink;
}ListNode;

typedef struct LinkedListType{
    int currentElementCount;
    ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList();
int addElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

#define TRUE    1
#define FALSE   0

#endif //DATASTRUCTURE_LINKEDLIST_H