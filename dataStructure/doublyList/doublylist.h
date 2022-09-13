//
// Created by 홍창섭 on 2022/09/13.
//

#ifndef DATASTRUCTURE_DOUBLYLIST_H
#define DATASTRUCTURE_DOUBLYLIST_H

#define TRUE    1
#define FALSE   0


typedef struct DoublyListNodeType{
    int data;
    struct DoublyListNodeType* lLink;
    struct DoublyListNodeType* rLink;
}DoublyListNode;

typedef struct DoublyListType{
    int currentElementCount;
    DoublyListNode headerNode;
}DoublyList;

DoublyList* createDoublyList();
int addElement(DoublyList* pList, int position, DoublyListNode element);
int removeElement(DoublyList* pList, int position);
DoublyListNode* getElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);
void deleteDoublyList(DoublyList* pList);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);


#endif //DATASTRUCTURE_DOUBLYLIST_H
