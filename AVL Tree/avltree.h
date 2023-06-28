#ifndef AVLTREE_H
#define AVLTREE_H

// libraries
#include <stdlib.h>

// node
typedef struct AVLNode {
  void *data;
  struct AVLNode *left, *right;
  int hidden, factor;
} AvlNode;
// tree
typedef struct AVLTree {
  AvlNode *root;
  int *size;
} AvlTree;

// macro
#define LEFT 1
#define CENTER 0
#define RIGHT -1

#define avlNode_factor(node) (node->factor)
#define avlNode_hidden(node) (node->hidden)
#define avlNode_data(node) (node->data)
#define avlNode_left(node) (node->left)
#define avlNode_right(node) (node->right)

#define avlTree_root(tree) (tree->root)
#define avlTree_size(tree) (tree->size)
#define avlTree_destroy(tree) (tree->destroy)
#define avlTree_compare(tree) (tree->compare)

#define avl_end(node) ( node == NULL )
#define avl_leaf(node) ( left(node) == NULL && right(node) == NULL )

// functions
void avl_rotate_lfet(AvlNode **node);
void avl_rotate_right(AvlNode **node);

#endif
