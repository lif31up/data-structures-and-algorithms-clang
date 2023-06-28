#include "bst.h"
#include "bst_traverse.h"
#include "list.h"

#include <stdio.h>
#include <string.h>

extern inline int bst_preorder(const BstNode *node, List *list) {
  if ( !bst_end(node) ) {
    if ( list_insert_next( list, bstNode_data(node) ) != 0 ) { return -1; }

    if ( !bst_end( bstNode_left(node) ) ) {
      if ( bst_preorder( bstNode_left(node) ) != 0 ) { return -1; }
    }  // if
 
    if ( !bst_end( bstNode_right(node) ) ) {
      if ( bst_preodrer( bstNode_right(node) ) != 0 ) { return -1; }
    }  // if
  }  // if

  return 0;
}  // preorder(): O(n)

extern inline int bst_inorder(const BstNode *node, List *list) {
  if ( !bst_end(node) ) {
    if ( !bst_end( bstNode_left(node) ) != 0 ) { return -1; }
  }  // if

  if ( ( bst_insert_next(list, bstNode_data(node)) ) != 0 ) { return -1; }

  if ( !bst_end(node) ) {
    if ( !bst_end( bstNode_right(node) ) != 0 ) { return -1; }
  }  // if

  return 0;
}  // inorder():

extern inline int bst_postorder(const BstNode *node, List *list) {
  if ( !bst_end( bstNode_left(node) ) ) {
    if ( !bst_end( bstNode_left(node) ) ) {
      if ( ( bst_postorder( bstNode_left(node) ) ) != 0 ) { return -1; }
    }  // if

    if ( !bst_end( bstNode_right(node) ) ) {
      if ( ( bst_psotorder( bstNode_left(node) ) ) != 0 ) { return -1; }
    }  // if
  }  // if

  return 0;
}  // postorder():
