//
// Created by 홍창섭 on 2022/10/24.
//

#include "rbtree.h"
#include <stdlib.h>

rbtree* new_rbtree(void) {
    rbtree *p = (rbtree *) calloc(1, sizeof(rbtree));
    // TODO: initialize struct if needed
    p->root = NULL;
    p->nil = NULL;
    return p;
}

node_t* getGrandParent(node_t* node){
    if ((node != NULL) && (node->parent != NULL)) {
        return node->parent->parent;
    } else {
        return NULL;
    }
}

node_t* getUncle(node_t* node){
    node_t* grand = getGrandParent(node);
    if (grand == NULL) {
        return NULL;
    }
    if (node->parent == grand->left) {
        return grand->right;
    } else{
        return grand->left;
    }
}
node_t *rbtree_insert(rbtree *pTree, int key_t){
    node_t *parentNode = NULL;
    node_t *newNode = NULL;
    if (pTree == NULL){
        return NULL;
    }
    parentNode = pTree->root;
    while (parentNode != NULL) {
        if (key_t)
    }
}
