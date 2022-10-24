//
// Created by 홍창섭 on 2022/10/21.
//

#ifndef DATASTRUCTURE_DEQUE_H
#define DATASTRUCTURE_DEQUE_H

typedef struct DequeNodeType
{
    char data;
    struct DequeNodeType* pRLink;
    struct DequeNodeType* pLLink;
}DequeNode;

typedef struct LinkedDequeType
{
    int currentElementCount;
    DequeNode* pFrontNode;//FrontNode의 Left Link = NULL
    DequeNode* pRearNode;//RearNode의 Right Link = NULL
}LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);
#endif //DATASTRUCTURE_DEQUE_H

#ifndef _COMMON_DEQUE_DEF_
#define _COMMON_DEQUE_DEF_

#define TRUE		1
#define FALSE		0

#endif