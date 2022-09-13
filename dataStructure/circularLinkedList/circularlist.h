//
// Created by 홍창섭 on 2022/09/13.
//

#ifndef DATASTRUCTURE_CIRCULARLIST_H
#define DATASTRUCTURE_CIRCULARLIST_H

typedef struct CircularListNodeType{
    int data;
    struct CircularListNodeType* pLink;
} CircularListNode;

typedef struct CircularListType {
    int currentElementCount;
    CircularListNode *pLink;
} CircularList;

CircularList* createCircularList();
int addElement(CircularList* pList, int position,CircularListNode element);
int removeElement(CircularList* pList,int position);
CircularListNode* getElement(CircularList* pList,int position);
void displayCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
void deleteCircularList(CircularList* pList);
void clearCircularList(CircularList* pList);

#define TRUE    1
#define FALSE   0

#endif//DATASTRUCTURE_CIRCULARLIST_H
