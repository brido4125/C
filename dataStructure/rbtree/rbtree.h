//
// Created by 홍창섭 on 2022/10/24.
//

#ifndef DATASTRUCTURE_RBTREE_H
#define DATASTRUCTURE_RBTREE_H

#include <stddef.h>

typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct node_t {
    color_t color;
    key_t key;
    struct node_t *parent, *left, *right;
} node_t;

typedef struct {
    node_t *root;
    node_t *nil;  // for sentinel
} rbtree;

rbtree *new_rbtree(void);
node_t *rbtree_insert(rbtree *pTree, const key_t);


#endif //DATASTRUCTURE_RBTREE_H
