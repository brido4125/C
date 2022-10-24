//
// Created by 홍창섭 on 2022/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode){
    BinTree *pReturn = NULL;
    pReturn = (BinTree *) malloc(sizeof(BinTree));
    if (pReturn != NULL) {
        pReturn->pRootNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
        if (pReturn->pRootNode != NULL) {
            //구조체의 멤버를 사용하기 위해 * 간접 지정 연산자 사용해야함
            *pReturn->pRootNode = rootNode;
            //*(pReturn->pRootNode) = rootNode;
            pReturn->pRootNode->pLeftChild = NULL;
            pReturn->pRootNode->pRightChild = NULL;
        } else {
            printf("error, in makeBinTree() - malloc BinTreeNode\n");
            free(pReturn);
            pReturn = NULL;
        }
    } else {
        printf("error in makeBinTree() - malloc BinTree\n");
    }
    return pReturn;
}

//Return : 생성된 child 반환
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
    BinTreeNode *pReturn = NULL;
    if (pParentNode != NULL) {
        if (pParentNode->pLeftChild == NULL) {
            pParentNode->pLeftChild = (BinTreeNode *) malloc(sizeof(BinTreeNode));
            if (pParentNode->pLeftChild != NULL) {
                //pParentNode->pLeftChild = &element;
                *(pParentNode->pLeftChild) = element;
                pParentNode->pLeftChild->pLeftChild = NULL;
                pParentNode->pLeftChild->pRightChild = NULL;
                pReturn = pParentNode->pLeftChild;
            } else {
                printf("error in memory allocation, insertLeftChildNodeBT()\n");
            }
        }
    } else {
        printf("error by already exists, insertLeftChildNodeBT()\n");
    }
    printf("Data = %c added \n", element.data);
    return pReturn;
}

//Return : 생성된 child 반환
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){
    BinTreeNode *pReturn = NULL;
    if (pParentNode != NULL) {
        if (pParentNode->pRightChild == NULL) {
            pParentNode->pRightChild = (BinTreeNode *) malloc(sizeof(BinTreeNode));
            if (pParentNode->pRightChild != NULL) {
                //pParentNode->pRightChild = &element;
                *(pParentNode->pRightChild) = element;
                pParentNode->pRightChild->pLeftChild = NULL;
                pParentNode->pRightChild->pRightChild = NULL;
                pReturn = pParentNode->pRightChild;
            } else {
                printf("error in memory allocation, insertLeftChildNodeBT()\n");
            }
        }
    } else {
        printf("error by already exists, insertLeftChildNodeBT()\n");
    }
    printf("Data = %c added \n", element.data);
    return pReturn;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree){
    BinTreeNode *pReturn = NULL;
    if (pBinTree != NULL) {
        pReturn = pBinTree->pRootNode;
    }
    return pReturn;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode){
    BinTreeNode *pReturn = NULL;
    if (pNode != NULL) {
        pReturn = pNode->pLeftChild;
    }
    return pReturn;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode){
    BinTreeNode *pReturn = NULL;
    if (pNode != NULL) {
        pReturn = pNode->pRightChild;
    }
    return pReturn;
}

void deleteBinTree(BinTree* pBinTree)
{
    if (pBinTree != NULL) {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
    }
}

//reculsive하게 들어감
void deleteBinTreeNode(BinTreeNode* pNode){
    if (pNode != NULL) {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
    }
}