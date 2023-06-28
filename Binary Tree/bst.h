#ifndef BST_H
#define BST_H

// libraries
#include <stdlib.h>

// Structs
typedef struct BSTNode {
  void *data;
  struct BSTNode *left, *right;
} BstNode;

typedef struct BSTree {
  int size;
  int (*compare)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  BstNode *root;
} BstTree;

// macros
#define bstNode_key(node) (node->key)
#define bstNode_data(node) (node->data)
#define bstNode_left(node) (node->left)
#define bstNode_right(node) (node->right)

#define bstTree_root(tree) (tree->root)
#define bstTree_size(tree) (tree->size)
#define bstTree_destroy(tree) (tree->destroy)
#define bstTree_compare(tree) (tree->compare)

#define bst_end(node) ( node == NULL )
#define bst_leaf(node) ( left(node) == NULL && right(node) == NULL )

// functions
void bst_init_tree(BstTree *tree, void (*destroy)(void *data));
void bst_destroy_tree(BstTree *tree);
int bst_ins_left(BstTree *tree, BstNode *node, const void *data);
int bst_ins_right(BstTree *tree, BstNode *node, const void *data);
void bst_rem_left(BstTree *tree, BstNode *node);
void bst_rem_right(BstTree *tree, BstNode *node);
int bst_merge_trees(BstTree *merge, BstTree *left, BstTree *right, const void *data);

#endif
