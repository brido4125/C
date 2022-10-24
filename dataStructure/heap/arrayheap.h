//
// Created by 홍창섭 on 2022/10/24.
//

#ifndef DATASTRUCTURE_ARRAYHEAP_H
#define DATASTRUCTURE_ARRAYHEAP_H

typedef struct HeapElementType{
    int key;
    char data;
}HeapNode;

typedef struct ArrayHeapType {
    int maxElementCount;
    int currentElementCount;
    HeapNode *pElement;
} ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element);
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap);
void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);


#endif //DATASTRUCTURE_ARRAYHEAP_H

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif