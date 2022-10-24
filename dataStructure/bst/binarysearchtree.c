//
// Created by 홍창섭 on 2022/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

BinSearchTree* createBinSearchTree(){
    BinSearchTree *pReturn = NULL;
    pReturn = (BinSearchTree *) malloc(sizeof(BinSearchTree));
    if (pReturn != NULL) {
        pReturn->pRootNode = NULL;
    } else {
        printf("error in createBinSearchTree()\n");
    }
    return pReturn;
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element){
    int ret = FALSE;
    BinSearchTreeNode *pParentNode = NULL;
    BinSearchTreeNode *pNewNode = NULL;

    if (pBinSearchTree == NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = pBinSearchTree->pRootNode;
    while (pParentNode != NULL) {
        if (element.key == pParentNode->key) {
            printf("error,already exists node in BST in insertElementBST()\n");
            ret = FALSE;
            return ret;
        } else if (element.key < pParentNode->key) {
            //왼쪽 노드가 더 이상 없으면 break
            if (pParentNode->pLeftChild == NULL) {
                break;
            }else {
                pParentNode = pParentNode->pLeftChild;
            }
        } else{
            if (pParentNode->pRightChild == NULL) {
                break;
            } else {
                pParentNode = pParentNode->pRightChild;
                }
            }
        }
    pNewNode = (BinSearchTreeNode *) malloc(sizeof(BinSearchTreeNode));
    if (pNewNode != NULL) {
        *pNewNode = element;
        pNewNode->pLeftChild = NULL;
        pNewNode->pRightChild = NULL;
        //BST가 비어있는 경우
        if (pParentNode == NULL) {
            pBinSearchTree->pRootNode = pNewNode;
        } else {
            if (pNewNode->key < pParentNode->key) {
                pParentNode->pLeftChild = pNewNode;
            } else {

                pParentNode->pRightChild = pNewNode;
            }
        }
        ret = TRUE;
    }else{
        printf("error in malloc BinSearchTreeNode in insertElementBST()\n");
        ret = FALSE;
    }
    return ret;
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key){
    int ret = TRUE;
    BinSearchTreeNode *pDelNode = NULL, *pParentNode = NULL;
    BinSearchTreeNode *pPredecessor = NULL, *pSuccessor = NULL;
    BinSearchTreeNode* pChildNode = NULL;

    if (pBinSearchTree == NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = NULL;
    pDelNode = pBinSearchTree->pRootNode;
    //삭제할 노드 탐색
    while (pDelNode != NULL) {
        if (key == pDelNode->key) {
            break;
        }
        pParentNode = pDelNode;
        if (key < pDelNode->key) {
            pDelNode = pDelNode->pLeftChild;
        } else {
            pDelNode = pDelNode->pRightChild;
        }
    }
    if (pDelNode == NULL) {
        printf("error, not exists key - [%d] in deleteElementBST()\n", key);
        ret = FALSE;
        return ret;
    }

    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = NULL;
            } else {
                pParentNode->pRightChild = NULL;
            }
        } else {
            pBinSearchTree->pRootNode = NULL;
        }
    } else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
        pPredecessor = pDelNode;
        pSuccessor = pDelNode->pLeftChild;//pSuccessor가 왼쪽 트리 중 가장 큰 값 가지는 노드(대체 노드)
        while (pSuccessor->pRightChild != NULL) {
            pPredecessor = pSuccessor;//대체 노드의 부모, 대체 노드의 자식을 달야함
            pSuccessor = pSuccessor->pRightChild;
        }
        pPredecessor->pRightChild = pSuccessor->pLeftChild;//대체 노드의 자식을 대체 노드의 부모에게 붙여줌
        pSuccessor->pLeftChild = pDelNode->pLeftChild;
        pSuccessor->pRightChild = pDelNode->pRightChild;

        //삭제할 노드의 부모 노드의 자식에 대체 노드 붙여줌
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pSuccessor;
            } else {
                pParentNode->pRightChild = pSuccessor;
            }
        } else{
            //삭제할 노드가 루트 노드인 경우
            pBinSearchTree->pRootNode = pSuccessor;
        }
    } else {
        if (pDelNode->pLeftChild != NULL) {
            pChildNode = pDelNode->pLeftChild;
        } else{
            pChildNode = pDelNode->pRightChild;
        }
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pChildNode;
            } else {
                pParentNode->pRightChild = pChildNode;
            }
        } else {
            pBinSearchTree->pRootNode = pChildNode;
        }
    }
    free(pDelNode);
    return ret;
}

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key){
    BinSearchTreeNode *pReturn = NULL;
    if (pBinSearchTree == NULL) {
        return NULL;
    }
    pReturn = searchInternalRecursiveBST(pBinSearchTree->pRootNode, key);
    return pReturn;
}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key){
    BinSearchTreeNode *pReturn = NULL;

    if (pTreeNode == NULL) {
        return NULL;
    }
    if (key == pTreeNode->key) {
        pReturn = pTreeNode;
    } else if (key < pTreeNode->key) {
        pReturn = searchInternalRecursiveBST(pTreeNode->pLeftChild, key);
    } else{
        pReturn = searchInternalRecursiveBST(pTreeNode->pRightChild, key);
    }
    return pReturn;
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
    if (pBinSearchTree != NULL) {
        deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
        free(pBinSearchTree);
    }
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{
    if (pTreeNode != NULL) {
        deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
        deleteBinSearchTreeInternal(pTreeNode->pRightChild);
        free(pTreeNode);
    }
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key){
    BinSearchTreeNode *pReturn = NULL;
    if (pBinSearchTree == NULL) {
        return NULL;
    }
    pReturn = pBinSearchTree->pRootNode;
    while (pReturn != NULL) {
        if (key == pReturn->key) {
            break;
        } else if (key < pReturn->key) {
            pReturn = pReturn->pLeftChild;
        } else {
            pReturn = pReturn->pRightChild;
        }
    }
    return pReturn;
}