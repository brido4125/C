//
// Created by 홍창섭 on 2022/09/07.
//
#ifndef DATASTRUCTURE_ARRAYLIST_H
#define DATASTRUCTURE_ARRAYLIST_H

typedef struct ArrayListNodeType {
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount; //최대 원소 갯수
    int currentElementCount; //현재 원소의 개수
    ArrayListNode *pElement;
}ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList,int position,ArrayListNode element);
int removeALElement(ArrayList* pList,int position);
ArrayListNode* getALElement(ArrayList* pList,int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#define TRUE    1
#define FALSE   0

#endif //DATASTRUCTURE_ARRAYLIST_H
