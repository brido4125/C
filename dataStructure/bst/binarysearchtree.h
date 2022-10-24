//
// Created by 홍창섭 on 2022/10/24.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

typedef struct BinSearchTreeNodeType{
    int key;
    char value;

    struct BinSearchTreeNodeType* pLeftChild;
    struct BinSearchTreeNodeType* pRightChild;
}BinSearchTreeNode;

typedef struct BinSearchTreeType{
    BinSearchTreeNode *pRootNode;
}BinSearchTree;

BinSearchTree* createBinSearchTree();
int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element);
int deleteElementBST(BinSearchTree* pBinSearchTree, int key);

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key);
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

#endif //DATASTRUCTURE_BINARYSEARCHTREE_H

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
