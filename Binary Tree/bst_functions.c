#include "BST.h"

#include <stdio.h>
#include <string.h>

void bst_init_tree(BstTree *tree, void (*destroy)(void *data)) {
  bstTree_size(tree) = 0; bstTree_destroy(tree) = destroy; bstTree_root(tree) = NULL;
  return;
}  // init(): initialize the binary tree. O(1)

void bst_destory_tree(BstTree *tree) {
  bst_rem_left(tree, NULL); bstTree_destroy(tree)( bstTree_root(tree) );
  memset(tree, 0, sizeof(BstTree)); return;
} // tree_destroy(): remove all the nodes from the tree. O(n)

int bst_ins_left(BstTree *tree, BstNode *node, const void *content) {
  BstNode *new, **position;

  if ( node == NULL ) {
    if ( bstTree_size(tree) > 0 ) { return -1; }
    position = &bstTree_root(tree);
  }  // if
  else {
    if ( bstNode_left(node) != NULL ) { return -1; }
    position = &bstNode_left(node);
  }  // else

  if ( ( new = (BstNode *)malloc(sizeof(BstNode)) ) == NULL ) { return -1; }
  bstNode_data(new) = (void *)content; bstNode_left(new) = NULL; bstNode_right(new) = NULL;
  *position = new; bstTree_size(tree) += 1;
  return 1;
}  // ins_left(): insert a node int the tree. O(1)

int bst_ins_right(BstTree *tree, BstNode *node, const void *content) {
  BstNode *new, **position;

  if ( node == NULL ) {
    if ( bstTree_size(tree) > 0 ) { return -1; }
    position = &bstTree_root(tree);
  }  // if
  else {
    if ( bstNode_right(node) != NULL ) { return -1; }
    position = &bstNode_left(node);
  }  // else

  if ( ( new = (BstNode *)malloc(sizeof(BstNode)) ) == NULL ) { return -1; }
  bstNode_data(new) = (void *)content; bstNode_left(new) = NULL; bstNode_right(new) = NULL;
  *position = new; bstTree_size(tree) += 1;
  return 1;
}  // ins_right(): insert a node int the tree. O(1)

extern void bst_rem_left(BstTree *tree, BstNode *node) {
  if ( bstTree_size(tree) == 0 ) { return; }

  BstNode **position;

  if ( node == NULL ) { position = &bstTree_root(tree); }
  else { position = &bstNode_left(node); }

  if ( *position != NULL ) {
    bst_rem_left(tree, *position); bst_rem_right(tree, *position);
    if ( bstTree_destroy(tree) != NULL ) { bstTree_destroy(tree)( bstNode_data((*position)) ); }
    free((*position)); *position = NULL;
    bstTree_size(tree) -= 1;
  }  // if

  return;
}  // rem_left(): remove all the nodes of left. O(n)

extern void bst_rem_right(BstTree *tree, BstNode *node) {
    if ( bstTree_size(tree) == 0 ) { return; }

  BstNode **position;

  if ( node == NULL ) { position = &bstTree_root(tree); }
  else { position = &bstNode_right(node); }

  if ( *position != NULL ) {
    bst_rem_left(tree, *position); bst_rem_right(tree, *position);
    if ( bstTree_destroy(tree) != NULL ) { bstTree_destroy(tree)( bstNode_data((*position)) ); }
    free((*position)); *position = NULL;
    bstTree_size(tree) -= 1;
  }  // if

  return;
}  // rem_left(): remove all the nodes of right. O(n)

int bst_merge_trees(BstTree *merge, BstTree *left, BstTree *right, const void *data) {
  bst_init_tree(merge, bstTree_destroy(left) );
  if ( bst_ins_left(merge, NULL, data) != 0 ) { bstTree_destroy(merge); return -1; }

  bstTree_root(merge)->left = bstTree_root(left);
  bstTree_root(merge)->right = bstTree_root(right);
  bstTree_size(merge) += ( bstTree_size(left) + bstTree_size(right) );

  bstTree_root(left) = NULL; bstTree_size(left) = 0;
  bstTree_root(right) = NULL; bstTree_size(right) = 0;

  return 0;
}  // merge(): merge the left and the right. O(1)
